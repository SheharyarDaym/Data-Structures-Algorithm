#include<iostream>
using namespace std;

class Node{
friend class SLL;
    int data;
    Node* link;
public:
    Node(){
        data = 0;
        link = NULL;
    }

    Node(int x){
        data = x;
        link = NULL;
    }

    void display(){
        cout << data << " ";
    }

    ~Node(){
        if(link!=NULL){
            delete link;
        }
    }
    
};

class SLL{
private:
    Node* start;

public: 
    SLL() : start(NULL) {}


    void insert_at_end(int x){
        if(start == NULL){
            start = new Node(x);
        }
        else{
            Node* temp;
            temp = start;
            while(temp->link!=NULL){
                temp = temp->link;
            }
            temp->link = new Node(x);
        }
        
    }

    void reverseSinglyLinkedList(){
        if(start == NULL || start->link == NULL) return;

        else{
            Node *temp = start;
            Node *prev = NULL;
            Node* next = NULL;

            while(temp != NULL){
                next = temp->link;
                temp->link = prev;
                prev = temp;
                temp = next;
            }
            start = prev;
        }
    }
    
    void display(){
        Node* temp = start;  
        while(temp != NULL){
            temp->display(); 
            temp = temp->link; 
        }
        cout << endl; 
    }

    ~SLL(){
        if(start != NULL){
            Node* temp = start;
            while(start != NULL){
                start = start->link;
                temp = start;
                delete temp;
            }
        }
    }
};


int main(){
    SLL s;
    // for(int i=0; i<5; i++){
    //     s.insert_at_end(i+1);
    // }
    s.insert_at_end(1);
    s.insert_at_end(2);
    s.reverseSinglyLinkedList();
    s.display();


    return 0;
}