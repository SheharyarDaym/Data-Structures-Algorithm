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
        cout << data << " ";
    }
};

class CDL{
private:
    Node* start;
    Node* end;
public:
    CDL() : start(NULL), end(NULL) {}
// Insertion
    void insert_End(int x);

    int removeMthNodes(int m);
    void display();
};


int CDL::removeMthNodes(int m)
{
    Node* temp = start;

    while(1){

        for(int i = 1; i < m; i++){
            temp = temp->next;
        }

        if(temp == start){
            start = start->next;
        }

        if(temp == end){
            end = end->prev;
        }

        Node *t = temp;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        
        delete t;

        temp = temp->next;
        if(start == end) break;
    }
    return temp->data;
}



int main(){
    CDL c;
    c.insert_End(1);
    c.insert_End(2);
    c.insert_End(3);
    c.insert_End(4);
    c.insert_End(5);
    c.insert_End(6);
    c.insert_End(7);

    c.removeMthNodes(2);

    c.display();

    return 0;
}


void CDL::insert_End(int x)
{
    if(start == NULL){
        start = new Node(x);
        end = start;
        start->next = start;
        start->prev = start;
    }
    else if(start == end){
        Node* t = new Node(x);
        end = t;
        start->next = end;
        start->prev = end;
        end->prev = start;
        end->next = start;
    }
    else{
        Node* temp = new Node(x);
        end->next = temp;
        temp->prev = end;
        temp->next = start;
        start->prev = temp;
        end = temp;
    }
}


void CDL::display()
{
    if(start == NULL){
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = start;
    do {
        temp->display();
        temp = temp->next;
    } while (temp != start);
    cout << endl;
}


