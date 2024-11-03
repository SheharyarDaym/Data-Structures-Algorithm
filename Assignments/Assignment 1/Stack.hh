// Stack using Single Linked List (SLL)
#include<iostream>
using namespace std;

template <class T>
class Node{
public:
    T data;
    Node* link;
    Node() : data(0), link(NULL) {}
    Node(T x) : data(x), link(NULL) {}
    void display() const {
        cout << "| " << data << " |" << endl;
    }
};

template <class T>
class Stack{
private:
    Node<T>* top;
public:
    Stack() : top(NULL) {}
    void PUSH(T x);
    T POP();
    T Top();
    bool isEmpty();
    void display();
};

template <class T>
void Stack<T>::PUSH(T x)
{
    if(top == NULL){
        top = new Node<T>(x);
    }
    else{
        Node<T>* temp = new Node<T>(x);
        temp->link = top;
        top = temp;
    }
}

template <class T>
T Stack<T>::POP()
{
    T n;
    if(top == NULL){
        cout << "Stack is EMPTY" << endl;
        return -1;
    }
    else{
         Node<T>* temp = top;
        top = top->link;
        n = temp->data;
        delete temp;
    }
    return n;
}

template <class T>
T Stack<T>::Top()
{
    if(top == NULL){
        cout << "Stack is EMPTY" << endl;
        return -1;
    }
    return top->data;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return (top == NULL);
}

template <class T>
void Stack<T>::display()
{
    if(top == NULL){
        cout << "Stack is EMPTY" << endl;
    }
    else{
        Node<T>* temp = top;
        while(temp != NULL){
            temp->display();
            temp = temp->link;
        }
        cout << endl;
    }
}
