#include<iostream>
#include<string>
#include"Stack.hh"
using namespace std;

class VariableNode{
public:
    string variableName;
    int value;
    VariableNode *next;
    VariableNode(string name, int val) : variableName(name), value(val), next(NULL) {}
};


bool isDigit(char ch){
    if(ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
        return true;
    return false;
}

bool validVariable(string var){
    if(var.empty()) return false;

    char ch = var[0];
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) return true;
    else return false;

    int i=0;
    while(var[i] != '\0'){
        if(((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) && isdigit(var[i])) return true;
        else return false;
        i++;
    }
    return true;
}



bool isOperator(char op)
{
    if(op == '/' || op == '*' || op == '+' || op == '-' || op == '(' || op == ')') return true;
    return false;
}

VariableNode* extractVariables(const string& expression) {
    VariableNode* head = NULL;
    VariableNode* tail = head;
    string variable;

    int i=0;
    while(expression[i] != '\0' || expression[i] == '\0'){ // =='\0' for checking variable at last
    
        if(expression[i] != '\0' && !isOperator(expression[i]) && expression[i] != ' '){
            variable += expression[i];
        } 

        else{

            if(!variable.empty() && validVariable(variable)){
                int val;
                cout << "Enter value of " << variable << " : ";
                cin >> val;
                VariableNode* temp = new VariableNode(variable, val);

                if(head == NULL){
                    head = temp;
                    tail = head;
                } 

                else{
                    tail->next = temp;
                    tail = temp;
                }
            }
            variable.clear();

        }
        if(expression[i] == '\0') break;

        i++;
    }
    return head;
}



bool is_Correct_Infix(const string& s)
{
    int i=0;
    int count = 0;
    int op = 0; 
    while(s[i] != '\0'){
        if(count == 1 && !isOperator(s[i]) && s[i-1] == ' ') return false;
        if(!isOperator(s[i]) && s[i] != ' '){
            count = 1;
            op = 0;
        } 
        else if(isOperator(s[i])){
            count = 0;
            op++;
        } 
        if(op > 1) return false;
        i++;
    }
    if(count == 1) return true;
    return false;
}


int precedence(char op)
{
    if(op == '/' || op == '*') return 5;
    else if(op == '+' || op == '-') return 4;
    return -1;
}

double solve(double left, double right, char op) 
{
    double ans;
    if(op == '/') ans = left / right;
    else if(op == '*') ans = left * right;
    else if(op == '+') ans = left + right;
    else if(op == '-') ans = left - right;
    return ans; 
}

string to_intString(const string& s, int& i)
{
    string convert;
    while(!isOperator(s[i]) && s[i] != ' ' && s[i] != '\0' && s[i] != '(' && s[i] != ')')
    {
        convert += s[i];
        i++;
    }
    convert = convert + ' ';
    return convert;
}

double to_int(const string& s, int& i)
{
    string convert;
    while (!isOperator(s[i]) && s[i] != ' ' && s[i] != '\0' && s[i] != '(' && s[i] != ')') 
    {
        convert += s[i];
        i++;
    }
    return stod(convert);
}

bool checkVariable(string ex, int i){
    string s;
    while(!isOperator(ex[i]) && ex[i] != ' ' && ex[i] != '\0' && ex[i] != '(' && ex[i] != ')'){
        s += ex[i];
        i++;
    }

    if(validVariable(s)) return true;
    return false;
}

string valueVariable(string ex, int& i, VariableNode* head){
    string s;
    while(!isOperator(ex[i]) && ex[i] != ' ' && ex[i] != '\0' && ex[i] != '(' && ex[i] != ')'){
        s += ex[i];
        i++;
    }
    VariableNode* temp = head;
    while(temp != NULL){
        if(s == temp->variableName) return to_string(temp->value);
        temp = temp->next;
    }
    return "";
}

string infixToPostfix(string infix, VariableNode* head)
{
    Stack<char> s;
    string postfix;
    int i = 0;

    while(infix[i] != '\0'){
        if(infix[i] == '('){
            s.PUSH(infix[i]);
            i++;
        } 

        else if(infix[i] == ')'){
            while(!s.isEmpty() && s.Top() != '(') 
            {
                postfix += s.Top();
                postfix += ' ';
                s.POP();
            }
            if(!s.isEmpty() && s.Top() == '(' )
                s.POP();
            i++;
        } 

        else if(!isOperator(infix[i]) && infix[i] != ' '){
            if(checkVariable(infix,i)){
                postfix += valueVariable(infix,i,head);
                postfix += " ";
            }
            else
                postfix += to_intString(infix, i);
        } 

        else if(isOperator(infix[i])){
            while(!s.isEmpty() && precedence(s.Top()) >= precedence(infix[i])) 
            {
                postfix += s.Top();
                postfix += ' ';
                s.POP();
            }
            s.PUSH(infix[i]);
            i++;
        } 


        else if (infix[i] == ' ') i++;
    }

    while(!s.isEmpty()) 
    {
        postfix += s.Top();
        postfix += ' ';
        s.POP();
    }

    cout << "Postfix: " << postfix << endl;
    return postfix;
}

double evaluatePostfix(string postfix)
{
    Stack<double> s1;
    int i = 0;
    while(postfix[i] != '\0')
    {
        if(!isOperator(postfix[i]) && postfix[i] != ' '){
            s1.PUSH(to_int(postfix, i));
        } 

        else if (isOperator(postfix[i])) 
        {
            double right = s1.Top(); s1.POP();
            double left = s1.Top(); s1.POP();
            double result = solve(left, right, postfix[i]);
            s1.PUSH(result);
            i++;
        } 

        else if(postfix[i] == ' ') i++;
    }

    return s1.Top();
}

int main(){
    string infix;
    cout << "Enter expression: ";
    getline(cin,infix);

    if(!is_Correct_Infix(infix)){
        cout << "Expression is not correct! " << endl;
        return 0;
    }

    VariableNode* var = extractVariables(infix);
    // while(var != NULL){
    //     cout << " --";
    //     cout << var->variableName << " : " << var->value << endl;
    //     var = var->next;
    // }

    string postfix = infixToPostfix(infix, var);
    double result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;



    return 0;
}



