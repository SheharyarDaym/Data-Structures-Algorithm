// Stack using Single Linked List (SLL)
#include<iostream>
using namespace std;

class NODE{
public:
    int data;
    NODE* link;
    NODE() : data(0), link(NULL) {}
    NODE(int x) : data(x), link(NULL) {}
    void display(){
        cout << "| " << data << " |" << endl;
    }
};

class Stack{
private:
    NODE* top;
public:
    Stack() : top(NULL) {}
    void PUSH(int x);
    int POP();
    bool isEmpty();
    void display();
};

void Stack::PUSH(int x)
{
    if(top == NULL){
        top = new NODE(x);
    }
    else{
        NODE* temp = new NODE(x);
        temp->link = top;
        top = temp;
    }
}

int Stack::POP()
{
    int n;
    if(top == NULL){
        cout << "Stack is EMPTY" << endl;
        return -1;
    }
    else{
        NODE* temp = top;
        top = top->link;
        n = temp->data;
        delete temp;
    }
    return n;
}

bool Stack::isEmpty()
{
    return (top == NULL);
}

void Stack::display()
{
    if(top == NULL){
        cout << "Stack is EMPTY" << endl;
    }
    else{
        NODE* temp = top;
        while(temp != NULL){
            temp->display();
            temp = temp->link;
        }
        cout << endl;
    }
}

/*int main(){
    Stack s;
    s.PUSH(5);
    s.PUSH(4);
    s.PUSH(3);
    s.PUSH(2);
    s.PUSH(2);

    s.display();

    s.POP();
    s.POP();

    s.display();
    
    return 0;
}*/