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

    void ZigZagList(){
        Node* temp = start;
        int count = 1;
        int swap;
        while(temp->link != NULL){
            if(count%2!=0){
                if(temp->data > temp->link->data){
                    swap=temp->data;
                    temp->data=temp->link->data;
                    temp->link->data=swap;
                }
            }
            else if(count%2==0){
                if(temp->data < temp->link->data){
                    swap=temp->data;
                    temp->data=temp->link->data;
                    temp->link->data=swap;
                }
            }
            temp=temp->link;
            count++;
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
    s.insert_at_end(15);
    s.insert_at_end(20);
    s.insert_at_end(45);
    s.insert_at_end(2);
    s.insert_at_end(35);
    s.ZigZagList();
    s.display();
    // 11->15->20->5->10
    return 0;
}

