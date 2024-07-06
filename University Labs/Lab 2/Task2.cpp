#include<iostream>
#include"Limited Stack.hh"
using namespace std;

Stack sortStack(Stack & s, int size)
{
    if(s.isEmpty()) return s;

    Stack s2(size);

    while(!s.isEmpty()) {
        int temp = s.POP();
        while(!s2.isEmpty() && s2.Top() > temp) {
            s.PUSH(s2.POP());
        }
        s2.PUSH(temp);
    }

    while(!s2.isEmpty()) {
        s.PUSH(s2.POP());
    }

    return s;
}


int main(){
    Stack s(6);
    s.PUSH(34);
    s.PUSH(3);
    s.PUSH(31);
    s.PUSH(98);
    s.PUSH(92);
    s.PUSH(23);
    s = sortStack(s,6);
    cout << "------------\n"; 
    s.display();
    return 0;
}

