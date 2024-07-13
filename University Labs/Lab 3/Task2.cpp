// Muhammad Sheharyar Khan Daym
// BCSF22M046

#include <iostream>
#include "Stack Template.h"
using namespace std;

class Queue {
private:
    Stack<int> stk1;
    Stack<int> stk2;

public:
    void enqueue(int x);
    int dequeue();
};

void Queue::enqueue(int x)
{
    while(!stk1.isEmpty()){     // values push to stk2
        stk2.PUSH(stk1.Top());
        stk1.POP();
    }
    if(stk1.isEmpty()){
        stk1.PUSH(x);
        while(!stk2.isEmpty()){     // values push to stk1
            stk1.PUSH(stk2.Top());
            stk2.POP();
        }
    }
}

int Queue::dequeue()
{
    if (stk1.isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;  
    }
    int front = stk1.Top();  
    stk1.POP(); 
    return front;
}


int main() {
    Queue q;
    int choice, value;

    while(1)
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) 
        {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                value = q.dequeue();
                if (value != -1)
                    cout << endl << "Dequeued from queue : " << value << endl << endl;
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}