// Stack using Array
#include<iostream>
using namespace std;


class Stack{
private:
    int size;
    int top;
    int* stk;
public:
    Stack(int size){
        this->size = size;
        top = -1;
        stk = new int[size];
    }
    void PUSH(int x);
    int POP();
    int Top();
    bool isEmpty();
    bool isFull();
    void display();
};

void Stack::PUSH(int x)
{
    if(top == size-1){
        cout << "Stack is FULL" << endl;
    }
    else{
        top++;
        stk[top] = x;
    }
}

int Stack::POP()
{
    if(top == -1){
        cout << "Stack is EMPTY" << endl;
        return -1;
    }
    return stk[top--];
}
int Stack::Top()
{
    if(top == -1){
        cout << "Stack is EMPTY" << endl;
        return -1;
    }
    return stk[top];
}

bool Stack::isEmpty()
{
    return (top == -1);
}

bool Stack::isFull()
{
    return (top == size-1);
}


void Stack::display()
{
    if(isEmpty()){
        cout << "Stack is EMPTY" << endl;
        return;
    }
    for(int i=top; i>=0; i--){
        cout << "|  " << stk[i] << "  |";
        if(i == top) cout << "   <- TOP";
        cout << endl;
    }
    cout << endl;
}








/*
int CDL::removeMthNodes(int m)
{
    Node* temp = start;
    int count = 1;
    while(temp->next != temp){
        if(count == m){
            Node* t = temp;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete t;
            count = 1;
        }
        temp = temp->next;
        count++;
    }
    return temp->data;   
}*/