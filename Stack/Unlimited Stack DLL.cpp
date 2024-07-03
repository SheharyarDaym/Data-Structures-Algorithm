// Stack using Double Linked List (DLL)
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node() : data(0), prev(NULL), next(NULL) {}
    Node(int x) : data(x), prev(NULL), next(NULL) {}
    void display(){
        cout << "| " << data << " |" << endl;
    }
};

class Stack{
private:
    Node* top;
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
        top = new Node(x);
    }
    else{
        Node* temp = new Node(x);
        temp->next = top;
        top->prev = temp;
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
        Node* temp = top;
        top = top->next;
        if(top != NULL)
            top->prev = NULL;
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
        return;
    }
    else{
        Node* temp = top;
        while(temp != NULL){
            temp->display();
            temp = temp->next;
        }
        cout << endl;
    }
}

int main(){
    Stack d;
    d.PUSH(5);
    d.PUSH(3);
    d.PUSH(6);
    d.PUSH(8);
    
    d.display();

    d.POP();

    d.display();

    return 0;
}