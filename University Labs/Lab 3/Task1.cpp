// Muhammad Sheharyar Khan Daym
// BCSF22M046

#include<iostream>
#include<string>
#include"Stack template.h"
using namespace std;

class Calculator{
private:
    string infix;
    string postfix;
    char delimeter;

private:
    bool isOperator(char op);
    int precedence(char op);
    double solve(double left, double right, char op);
    string to_intString(const string& s, int& i);
    double to_int(const string& s, int& i);

public:
    Calculator() : delimeter(' ') {}
    Calculator(string i) : infix(i), delimeter(' ') {}
    void setInfix(string i);
    string getPostfix();
    string infixToPostfix();
    double evaluatePostfix();
};


bool Calculator::isOperator(char op)
{
    if(op == '/' || op == '*' || op == '+' || op == '-') return true;
    return false;
}

int Calculator::precedence(char op)
{
    if(op == '/' || op == '*') return 5;
    else if(op == '+' || op == '-') return 4;
    return -1;
}

double Calculator::solve(double left, double right, char op) 
{
    double ans;
    if(op == '/') ans = left / right;
    else if(op == '*') ans = left * right;
    else if(op == '+') ans = left + right;
    else if(op == '-') ans = left - right;
    return ans; 
}

string Calculator::to_intString(const string& s, int& i)
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

double Calculator::to_int(const string& s, int& i)
{
    string convert;
    while (!isOperator(s[i]) && s[i] != ' ' && s[i] != '\0' && s[i] != '(' && s[i] != ')') 
    {
        convert += s[i];
        i++;
    }
    return stod(convert);
}

void Calculator::setInfix(string i)
{
    infix = i;
}

string Calculator::getPostfix()
{
    return postfix;
}

string Calculator::infixToPostfix()
{
    Stack<char> s;
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
            if (!s.isEmpty() && s.Top() == '(' )
            s.POP();
            i++;
        } 

        else if (!isOperator(infix[i]) && infix[i] != delimeter) {
            postfix += to_intString(infix, i);
        } 

        else if (isOperator(infix[i])) 
        {
            while(!s.isEmpty() && precedence(s.Top()) >= precedence(infix[i])) 
            {
                postfix += s.Top();
                postfix += ' ';
                s.POP();
            }
            s.PUSH(infix[i]);
            i++;
        } 


        else if (infix[i] == delimeter) i++;
    }

    while(!s.isEmpty()) 
    {
        postfix += s.Top();
        postfix += delimeter;
        s.POP();
    }

    // cout << "Postfix: " << postfix << endl;
    return postfix;
}

double Calculator::evaluatePostfix()
{
    postfix = infixToPostfix(); // Just function calling..
    cout << "Postfix: " << postfix << endl;
    Stack<double> s1;
    int i = 0;
    while(postfix[i] != '\0')
    {
        if(!isOperator(postfix[i]) && postfix[i] != delimeter){
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

        else if(postfix[i] == delimeter) i++;
    }

    return s1.Top();
}

int main(){
    string infix;
    cout << "Enter infix: ";
    getline(cin, infix);

    Calculator c(infix);
    cout << c.evaluatePostfix();
    cout << endl;

    return 0;
}