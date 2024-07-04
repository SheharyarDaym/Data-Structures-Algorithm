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
// Constructor
    CDL() : start(NULL), end(NULL) {}
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

void CDL::insert_First(int x)
{
    if(start == NULL){
        start = new Node(x);
        end = start;
        start->next = start;
        start->prev = start;
    }
    else if(start == end){
        Node* t = new Node(x);
        start = t;
        start->next = end;
        end->next = start;
        start->prev = end;
        end->prev = start;
    }
    else{
        Node* temp = new Node(x);
        temp->next = start;
        start->prev = temp;
        temp->prev = end;
        end->next = temp;
        start = temp;
    }
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

void CDL::insert_Before(int x, int y)
{
    if(start == NULL) return;
    else if(start->data == x){
        Node* temp = new Node(y);
        temp->next = start;
        start->prev = temp;
        temp->prev = end;
        end->next = temp;
        start = temp;
    }
    else{
        Node* temp = start;
        do {
            temp = temp->next;
        } while(temp->data != x && temp != start);

        if(temp->data == x){
            Node* t = new Node(y);
            temp->prev->next = t;
            t->prev = temp->prev;
            t->next = temp;
            temp->prev = t;
        }
    }
}

void CDL::insert_After(int x, int y)
{
    if(start == NULL) return;
    else if(end->data == x){
        Node* t = new Node(y);
        end->next = t;
        t->prev = end;
        end = t;
        end->next = start;
        start->prev = end;
    }
    else{
        Node* temp = start;
        do {
            temp = temp->next;
        } while(temp->data != x && temp != start);
        if(temp->data == x){
            Node* t = new Node(y);
            temp->next->prev = t;
            t->next = temp->next;
            temp->next = t;
            t->prev = temp;
        }
        else    
            cout << "Value Not Found" << endl;
    }
}

void CDL::sortedAsc(int x)
{
    if(start == NULL){
        start = new Node(x);
        end = start;
        start->next = start;
        start->prev = start;
    }
    else if(start->data >= x){
        Node* t = new Node(x);
        t->next = start;
        start->prev = t;
        start = t;
        start->prev = end;
        end->next = start;
    }
    else{
        Node* temp = start;
        do {
            temp = temp->next;
        } while(temp != start && temp->data <= x);
        if(temp == start){
            Node* t = new Node(x);
            end->next = t;
            t->prev = end;
            end = t;
            end->next = start;
            start->prev = end;
        }
        else if(temp->data >= x){
            Node* t = new Node(x);
            temp->prev->next = t;
            t->prev = temp->prev;
            t->next = temp;
            temp->prev = t;
        }

    }
}

void CDL::sortedDsc(int x)
{
    if(start == NULL){
        start = new Node(x);
        end = start;
        start->next = start;
        start->prev = start;
    }
    else if(start->data <= x){
        Node* t = new Node(x);
        t->next = start;
        start->prev = t;
        start = t;
        start->prev = end;
        end->next = start;
    }
    else{
        Node* temp = start;
        do {
            temp = temp->next;
        } while(temp != start && temp->data >= x);
        if(temp == start){
            Node* t = new Node(x);
            end->next = t;
            t->prev = end;
            end = t;
            end->next = start;
            start->prev = end;
        }
        else if(temp->data <= x){
            Node* t = new Node(x);
            temp->prev->next = t;
            t->prev = temp->prev;
            t->next = temp;
            temp->prev = t;
        }

    }
}


void CDL::delete_first()
{
    if(start == NULL) return;
    else if(start == end){
        delete start;
        start = NULL;
        end = start;
        return;
    }
    else{
        Node* temp = start;
        start = start->next;
        delete temp;
        end->next = start;
        start->prev = end;       
    }
}

void CDL::delete_first_occurence(int x)
{
    if(start == NULL) return;
    else if(start == end){
        if(start->data == x){
            delete start;
            start = NULL;
            end = NULL;
        }
        return;
    }
    else if(start->data == x){
        Node* t = start;
        start = start->next;
        delete t;
        start->prev = end;
        end->next = start;
    }
    else{
        Node* temp = start;
        do{
            temp = temp->next;
        } while(temp != start && temp->data != x);
         
        if(temp == end && temp->data == x){
            end = end->prev;
            delete temp;
            start->prev = end;
            end->next = start;
            return;
        }
        else if(temp->data == x){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return;
        }
    }
}

void CDL::delete_last()
{
    if(start == NULL) return;
    else if(start == end){
        delete start;
        start = NULL;
        end = NULL;
    }
    else{
        Node* temp = end;
        end = end->prev;
        delete temp;
        start->prev = end;
        end->next = start;
    }
}


void CDL::delete_All_occurence(int x)
{
    if(start == NULL) return;
    else if(start == end && start->data == x){
        delete start;
        start = NULL;
        end = NULL;
        return;
    }
    Node* t = start;
    do{
        if(t->data == x){
            start = start->next;
            delete t;
            t = start;
        }
    }while(t->data == x);
    if(start == end) return;
    else{
        Node* temp = start;
        do{
            if(temp->data == x){
                Node* t = temp;
                Node* t2 = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete t;
                temp = t2;
            }
            else{
                temp = temp->next;
            }
        }while(temp!=start);

    }

}


void CDL::delete_kth(int x)
{
    if(start == NULL) return;
    else if(x == 0) return;
    Node* temp = start;
    int count = 1;
    do{
        temp = temp->next;
        count++;
    } while(temp != start);

    if(count < x){
        cout << "Node not found" << endl;
        return;
    }
    else if(start == end){
        delete start;
        start = NULL;
        end = NULL;
        return;
    }
    else if(x == 1){
        Node* t = start;
        start = start->next;
        delete t;
        start->prev = end;
        end->next = start;
    }
    else{
        count = 1;
        temp = start;
        do{
            temp = temp->next;
            count++;
        } while(temp != start && count != x);

        if(temp == start){
            temp = end;
            end = end->prev;
            delete temp;
            end->next = start;
            start->prev = end;
        }
        else if(count == x){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp; 
        }
    }

}

bool CDL::isEmpty()
{
    if(start == NULL) return true;
    else return false;
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


int main(){
    CDL d;
    // d.insert_End(5);
    // d.insert_End(4);
    // d.insert_End(3);

    // d.insert_After(3,1);
    // d.insert_Before(5,1);

    // for(int i=0; i<5; i++){
    //     d.insert_End(i+1);
    // }
    // d.insert_End(3);
    d.insert_End(4);
    d.insert_End(4);
    d.insert_End(4);
    d.insert_End(4);
    d.insert_End(4);
    // d.insert_End(7);
    // d.insert_End(2);
    d.insert_End(4);

    d.display();
    d.delete_All_occurence(4);
    d.display();
    return 0;
}
