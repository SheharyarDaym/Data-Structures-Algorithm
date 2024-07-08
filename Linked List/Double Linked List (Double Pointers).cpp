// Double Linked List with Double pointers  --> start & end

#include<iostream>
using namespace std;

class Node{
friend class DLL2;
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

class DLL2{
private:
    Node* start;
    Node* end;
public:
    // Constructor
    DLL2() : start(NULL), end(NULL) {}
// Insert
    void insert_Append(int x);
    void insert_At_First(int x);
    void insert_Before(int x, int y);
    void insert_After(int x, int y);
// Sorted Insertion
    void sortedAsc(int x);
    void sortedDsc(int x);

// Delete
    void delete_First(int x);
    void delete_Kth(int x, int occurence);
    void delete_All(int x);
// Display
    void display();
    void print_Reverse();
// Reverse
    void list_Reverse();

// Functions
    bool isPalindrome();
    void Right_rotate_List(int x);
    void Left_rotate_List(int x);

// Destructor
    ~DLL2(){
        if(start != NULL){
            Node* temp = start;
            while(start != NULL){
                start = start->next;
                temp = start;
                delete temp;
            }
        }
    }
};

void DLL2::insert_Append(int x)
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

void DLL2::insert_At_First(int x)
{
    if(start == NULL){
        start = new Node(x);
    }
    else{
        Node* temp = new Node(x);
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
}

void DLL2::insert_Before(int x, int y)
{
    if(start == NULL) return;
    // Found at start
    if(start->data == x){
        Node* temp = new Node(y);
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
    // Found at End
    else if(end->data == x){
        Node* temp = new Node(y);
        end->prev->next = temp;
        temp->prev = end->prev;
        end->prev = temp;
        temp->next = end;
    }
    // Found in Middle
    else{
        Node* temp = start;
        while(temp != NULL){
            if(temp->data == x){
                Node* t = new Node(y);
                temp->prev->next = t;
                t->prev = temp->prev;
                temp->prev = t;
                t->next = temp;
                return;                        
            }
            temp = temp->next;
        }
    }
    cout << "Value Not found" << endl;
}

void DLL2::insert_After(int x, int y)
{
    if(start == NULL) return;
    // Found at end
    if(end->data == x){
        Node* t = new Node(y);
        end->next = t;
        t->prev = end;
        end = t;
        return;
    }
    Node* temp = start;
    while(temp->data != x && temp != NULL){
        temp = temp->next;
    }
    if(temp->data == x){
        Node* t = new Node(y);
        temp->next->prev = t;
        t->next = temp->next;
        temp->next = t;
        t->prev = temp;
    }
    else{
        cout << "Value Not Found! " << endl;
    }
}


void DLL2::sortedAsc(int x)
{
    if(start == NULL){
        start = new Node(x);
        end = start;
    }
    else if(start->data >= x){
        Node* t = new Node(x);
        t->next = start;
        start->prev = t;
        start = t;
    }
    else{
        Node* temp = start;
        while(temp != NULL && temp->data <= x){
            temp = temp->next;
        }
        if(temp == NULL){
            Node* t = new Node(x);
            end->next = t;
            t->prev = end;
            end = t;
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

void DLL2::sortedDsc(int x)
{
    if(start == NULL){
        start = new Node(x);
        end = start;
    }
    else if(start->data <= x){
        Node* t = new Node(x);
        t->next = start;
        start->prev = t;
        start = t;
    }
    else{
        Node* temp = start;
        while(temp != NULL && temp->data >= x){     // if temp->data write first, it will 
            temp = temp->next;                      // try to derefence nullptr, so it dangerous for output..
        }
        if(temp == NULL){
            Node* t = new Node(x);
            end->next = t;
            t->prev = end;
            end = t;
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

void DLL2::delete_First(int x)
{
    if(start == NULL) return;
    else if(start->next == NULL && start->data == x){
        delete start;
        start = NULL;
    }
    else if(start->data == x){
        Node* temp = start;
        start = start->next;
        start->prev = NULL;
        delete temp;
    }
    else{
        Node* temp = start;
        while(temp != NULL && temp->data != x){
            temp = temp->next;
        }
        if(temp->data == x){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
}

void DLL2::delete_Kth(int x, int occurence)
{
    int count = 0;
    Node* temp = start;

    while(temp != NULL){
        if(temp->data == x){
            count++;
            if(count == occurence){
                // Start
                if(temp == start && start->next!=NULL){
                    start = start->next;
                    start->prev = NULL;
                    delete temp;
                    return;
                }
                // Start <--> End
                else if(start == end){
                    delete start;
                    start = NULL;
                    end = NULL;
                    return;
                }
                // last
                if(temp == end){
                    temp->prev->next = NULL;
                    end = temp->prev;
                    delete temp;
                    return;
                }
                // Middle
                Node* p = temp->prev;
                Node* n = temp->next;
                p->next = n;
                n->prev = p;
                delete temp;
                break;  
            }
        }
        temp = temp->next;
    }
}

void DLL2::delete_All(int x)
{
    if(start == NULL) return;
    Node* temp = start;
    while(temp->data == x && temp != NULL){
        Node* t = start;
        start = start->next;
        start->prev = NULL;
        temp = start;
        delete t;
    }
    while(temp != NULL){
        if(temp->data == x){
            Node* t = temp;
            if(temp->prev != NULL){
                temp->prev->next = temp->next;
            }
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }
            temp = temp->next;
            delete t;
        }
        else
        temp = temp->next;
    }
}


void DLL2::display()
{
    Node* temp = start;
    while(temp != NULL){
        temp->display();
        temp = temp->next;
    }
    cout << endl;
}

void DLL2::print_Reverse()
{
    Node* temp = end;
    while(temp!=NULL){
        temp->display();
        temp = temp->prev;
    }
}

void DLL2::list_Reverse()
{
    Node* temp = start;
    start = end;
    end = temp;

    temp = start;

    while(temp!=NULL){
        Node* t = temp->next;
        temp->next = temp->prev;
        temp->prev = t;
        temp = temp->next;
    }
}

bool DLL2::isPalindrome()
{
    Node* temp1 = start;
    Node* temp2 = end;
    while(temp1 != temp2){
        if(temp1->data != temp2->data) return false;
        temp1 = temp1->next;
        temp2 = temp2->prev;
    }
    return true;
}

void DLL2::Left_rotate_List(int x)
{
    if(start == NULL) return;
    else if(start == end) return;

    // Finding length of list
    int lenght = 0;
    Node* temp = start;
    while(temp != NULL){
        temp = temp->next;
        lenght++;
    }

    int count = 0;
    x = x % lenght;
    if(x==0) return;
    temp = start;
    while(count < x && temp != NULL){
        temp = temp->next;
        count++;
    }
    start->prev = end;
    end->next = start;
    start = temp;
    end = temp->prev;
    end->next = NULL;
    start->prev = NULL;
}

void DLL2::Right_rotate_List(int x)
{
    if(start == NULL) return;
    else if(start == end) return;

    // Finding length of list
    int lenght = 0;
    Node* temp = start;
    while(temp != NULL){
        temp = temp->next;
        lenght++;
    }

    int count = 0;
    x = x % lenght;
    if(x==0) return;
    temp = start;
    while(count < (lenght-x) && temp != NULL){
        temp = temp->next;
        count++;
    }
    start->prev = end;
    end->next = start;
    start = temp;
    end = temp->prev;
    end->next = NULL;
    start->prev = NULL;
}
