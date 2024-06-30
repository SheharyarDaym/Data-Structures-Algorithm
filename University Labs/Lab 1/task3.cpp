#include<iostream>
using namespace std;

class Node{
friend class DLL;
private:
    int data;
    Node* prev;
    Node* next;
public:
    Node() : data(0), prev(NULL), next(NULL) {}
    Node(int x) : data(x), prev(NULL), next(NULL) {}
    void display(){
        cout << data << " ";
    }
};

class DLL{
private:
    Node* start;
    Node* end;
public:
    // Constructor
    DLL() : start(NULL), end(NULL) {}
    void insert_Append(int x)
    {
        if(start == NULL){
            start = new Node(x);
            end = start;
        }
        else{
            end->next = new Node(x);
            end->next->prev = end;
            end = end->next; 
        }
    }
     void display()
    {
        Node* temp = start;
        while(temp != NULL){
            temp->display();
            temp = temp->next;
        }
        cout << endl;
    }
    void deleteNthNodeFromTheEnd(int n){
        if(start == NULL) return;
        Node* temp = end;
        int count = 0;
        while(temp != NULL){
            count++;
            if(count == n)
            {
                if(temp->next == NULL){
                    temp->prev->next = NULL;
                    delete temp;
                    break;
                }
                else if(temp->prev == NULL){
                    temp->next->prev = NULL;
                    start = start->next;
                    delete temp;
                    break;
                }
                else{
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    break;
                }
            }
            temp = temp->prev;
        }
    }

};
       
    




int main(){
    DLL d;
    for(int i=0; i<5; i++){
        d.insert_Append(i+1);
    }
    d.deleteNthNodeFromTheEnd(3);

    d.display();
    return 0;
}