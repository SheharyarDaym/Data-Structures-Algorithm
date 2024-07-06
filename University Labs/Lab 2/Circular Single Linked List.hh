#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* link;
    Node() : data(0), link(NULL) {}
    Node(int x) : data(x), link(NULL) {}
    void display(){
        cout << data << " ";
    }
};

class CSL{
public:
    Node* start;
    Node* end;
    CSL() : start(NULL), end(NULL) {}
// Insertion
    void insert_First(int x);
    void insert_End(int x);
    void insert_Before(int x, int y);
    void insert_After(int x, int y);
    void sortedAsc(int x);
    void sortedDsc(int x);
// Deletion
    void delete_first();
    void delete_first_occurence(int x);
    void delete_last();
    void delete_kth(int x);
    void delete_All_occurence(int x);
    void delete_kth_occurence(int x, int y);
// Empty 
    bool isEmpty();

    void display();
};

void CSL::insert_First(int x)
{
    if(start == NULL){
        start = new Node(x);
        end = start;
        end->link = start;
    }
    else{
        Node* temp = new Node(x);
        temp->link = start;
        end->link = temp;
        start = temp;
    }
}

void CSL::insert_End(int x)
{
    if(start == NULL){
        start = new Node(x);
        end = start;
        end->link = start;
    }
    else{
        Node* temp = new Node(x);
        end->link = temp;
        end = temp;
        end->link = start;
    }
}

void CSL::insert_Before(int x, int y)
{
    if(start == NULL) return;
    else if(start->data == x){
        Node* temp = new Node(y);
        temp->link = start;
        start = temp;
        end->link = temp;
    }
    else{
        Node* temp = start;
        Node* prev = NULL;
        do{
            if(temp->data == x){
                Node* t = new Node(y);
                prev->link = t;
                t->link = temp;
                break;
            }
            prev = temp;
            temp = temp->link;
        }while(temp != start);
    }
}

void CSL::insert_After(int x, int y)
{
    if(start == NULL) return;
    else if(end->data == x){
        Node* temp = new Node(y);
        end->link = temp;
        end = temp;
        end->link = start;
    }
    else{
        Node* temp = start;
        do{
            if(temp->data == x){
                Node* t = new Node(y);
                t->link = temp->link;
                temp->link = t;
                break;
            }
            temp = temp->link;
        }while(temp != start);
    }
}

void CSL::sortedAsc(int x)
{
    if(start == NULL){
        start = new Node(x);
        end = start;
        end->link = start;
    }
    else if(start->data >= x){
        Node* temp = new Node(x);
        temp->link = start;
        start = temp;
        end->link = start;
    }
    else if(end->data <= x){
        Node* temp = new Node(x);
        end->link = temp;
        end = temp;
        end->link = start;
    }
    else{
        Node* temp = start;
        do{
            if(temp->data < x){
                Node* t = new Node(x);
                t->link = temp->link;
                temp->link = t;
                break;
            }
            temp = temp->link;
        }while(temp != start);
    }
}

void CSL::sortedDsc(int x)
{
    if(start == NULL){
        start = new Node(x);
        end = start;
        end->link = start;
    }
    else if(start->data <= x){
        Node* temp = new Node(x);
        temp->link = start;
        start = temp;
        end->link = start;
    }
    else if(end->data >= x){
        Node* temp = new Node(x);
        end->link = temp;
        end = temp;
        end->link = start;
    }
    else{
        Node* temp = start;
        do{
            if(temp->data > x){
                Node* t = new Node(x);
                t->link = temp->link;
                temp->link = t;
                break;
            }
            temp = temp->link;
        }while(temp != start);
    }
}


void CSL::display()
{
    if(start == NULL){
        cout << "List is empty" << endl;
    }
    else{
        Node* temp = start;
        do{
            temp->display();
            temp = temp->link;
        }while(temp != start);
        cout << endl;
    }
}

/*int main(){
    CSL s;
    // s.insert_End(4);
    // s.insert_End(5);
    // s.insert_End(6);

    // s.insert_After(6,10);
    // s.sortedAsc(4);
    // s.sortedAsc(3);
    // s.sortedAsc(8);
    // s.sortedAsc(98);
    // s.sortedAsc(-1);

    s.sortedDsc(4);
    s.sortedDsc(4);
    s.sortedDsc(3);
    s.sortedDsc(10);
    s.sortedDsc(4);
    s.sortedDsc(3);
    s.sortedDsc(10);


    s.display();
    return 0;
}*/