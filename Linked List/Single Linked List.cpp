#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* link;

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
    
};

class SLL{
private:
    Node* start;
public: 
    SLL() : start(NULL) {}
// Insert
    void insert_at_end(int x);
    void insert_at_start(int x);
    void update_at(int x, int y);
    void insert_before(int x, int y);
    void insert_after(int x, int y);
// Search
    Node* search(int x);
// Delete
    void delete_at_end();
    void delete_at_start();
    void delete_at(int x);
    void delete_All_occurences(int x);
    void delete_alternate_element();
    void remove_nth_end(int x);
    void remove_nth(int x);
// Check Empty list
    bool isEmpty();
// Functions
    void reverse_List();
    void rotate_List(int x);
//Display
    void display();
};

    void SLL::insert_at_end(int x)
    {
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


    void SLL::insert_at_start(int x)
    {
        Node* temp;
        temp = new Node(x);
        temp->link = start;
        start = temp;
    }

    void SLL::update_at(int x, int y)
    {
        Node* temp;
        temp = start;
        while(temp->data != x){
            temp = temp->link;
        }
        if(temp->data == x){
            temp->data = y;
        }
        else{
            cout << "Value Not found" << endl;
        }
    }


    Node* SLL::search(int x)
    {
        Node* temp;
        temp = start;
        while(temp->link!=NULL){
            if(temp->data == x){
                cout << "Found" << endl;
                return temp;
            } 
            temp = temp->link;
        }
            cout << "Not Found" << endl;
    }

    void SLL::insert_before(int x, int y)
    {
        Node* temp;
        Node* prev;
        temp = start;
        prev = start;

        while(temp->data != x){
            prev = temp;
            temp = temp->link;
        }
        if(prev == temp || temp == start){ 
            Node* t;
            t = new Node(y);
            t->link = temp;
            start = t;
        }
        else{
        Node* t2;
        t2 = new Node(y);
        prev->link = t2;
        t2->link = temp;
        }
    }

    void SLL::insert_after(int x, int y)
    {
        Node* temp;
        Node* after;
        temp = start;

        while(temp->data != x){
            temp = temp->link;
        }
        if(temp->link == NULL){
            Node* t1;
            t1 = new Node(y);
            temp->link = t1;
        }

        else{
            after = temp->link;
            Node* t;
            t = new Node(y);
            temp->link = t;
            t->link = after;
        }
    }

    void SLL::delete_at_end()
    {
        if(start == NULL){
            return;
        }
        if(start->link == NULL){
            delete start;
            start = NULL;
            return;
        }

        Node* temp;
        Node* prev;
        temp = start;
        prev = start;
        while(temp->link != NULL){
            prev = temp;
            temp = temp->link;
        }
        prev->link = NULL;
        delete temp;
    }

    void SLL::delete_at_start()
    {
        if(start == NULL) return;
        if(start->link == NULL){
            delete start;
            start = NULL;
        }
        Node* temp = start;
        start = start->link;
        delete temp;
    }

    void SLL::delete_at(int x)
    {
        if(start == NULL) return;
        Node* temp = start;
        if(temp->data == x){
            start = start->link;
            delete temp;
            return;
        }
        Node* prev = start;
        Node* after = start;

        while(temp->data != x && temp != NULL){
            prev = temp;
            temp = temp->link;
        }

        after = temp->link;
        prev->link = after;
        delete temp;
    }


    void SLL::delete_All_occurences(int x)
    {
        if(start == NULL) return;
        else if(start->data == x && start->link == NULL){
            delete start;
            start = NULL;
            return;
        }
        Node* dummy = new Node(0);
        dummy->link = start;
        Node* temp = start;
        Node* prev = dummy;
        // prev->link = start;
        while(temp != NULL){
            if(temp->data == x){
                prev->link = temp->link;
                delete temp;
                
                temp = prev->link;
            }
            else{
                prev = temp;
                temp = temp->link;
            }
        }
        start = dummy->link;

    }

    void SLL::delete_alternate_element()
    {
        if(start==NULL) return;
        Node* temp = start;
        Node* del = NULL;
        while(temp->link != NULL && temp != NULL){
            del = temp->link;
            temp->link = del->link;
            delete del;
            temp = temp->link;
        }
    }

    void SLL::remove_nth_end(int x)
    {
        int end = 0;
        Node* temp = start;
        while(temp != NULL){
            end++;
            temp = temp->link;
        }
        end++;
        end = end - x;
        cout << "End = " << end << endl;
        remove_nth(end);
        

    }

    void SLL::remove_nth(int x)
    {
        if(start == NULL) return;
        Node* temp = start;
        if(x == 1){
            start = temp->link; 
            delete temp;       
            return;
        }
        Node* prev = start;
        int count = 1;
        while(count < x && temp != NULL){
            prev = temp;
            temp = temp->link;
            count++;
        }
        if(count == x){
            prev->link = temp->link;
            delete temp;
        }
    }

    bool SLL::isEmpty()
    {
        if(start == NULL) return true;
        return false;
    }

    void SLL::reverse_List()
    {
        if(start == NULL) return;
        Node* prev = NULL;
        Node* temp = start;
        Node* after = temp->link;

        while(temp != NULL){
            after = temp->link; 
            temp->link = prev;
            prev = temp;
            temp = after;
        }
        start = prev;
    }

    void SLL::rotate_List(int x)
    {
        if(start == NULL) return;
        else if(start->link == NULL) return;

        // Finding length of list
        int lenght = 0;
        Node* temp = start;
        Node* end = NULL;
        while(temp != NULL){
            end = temp;
            temp = temp->link;
            lenght++;
        }

        int count = 0;
        x = x % lenght;
        if(x==0) return;
        temp = start;
        Node* prev = NULL;
        while(count < (lenght-x) && temp != NULL){
            prev = temp;
            temp = temp->link;
            count++;
        }
        if(prev != NULL) prev->link = NULL;
        end->link = start;
        start = temp;
        end = prev;
    }


    void SLL::display()
    {
        Node* temp = start;  
        while(temp != NULL){
            temp->display(); 
            temp = temp->link; 
        }
        cout << endl; 
    }
    



int main(){
    // Node* n = new Node(5);
    // cout << n->data << " " << n->link << endl;
    SLL a;
    a.insert_at_end(1);
    a.insert_at_end(2);
    a.insert_at_end(3);
    a.insert_at_end(4);
    a.insert_at_end(5);
    // a.delete_alternate_element();
    // a.update_at(2,0);
    // a.delete_All_occurences(7);
    // a.rotate_List(1);
    a.display();

    a.display();
    // a.remove_nth_end(3);
    // a.reverse_List();
    // cout << a.isPalindrome() << endl;
    // a.display();
    // a.remove_nth(2);
    // a.display();
    // a.delete_at_start();
    
    // SLL b;
    // cout << "Empty: " << b.isEmpty();


    // cout << "Insert Before" << endl;
    // a.insert_after(2,5);
    // a.display();


    // cout << "Search------\n";
    // Node* n = a.search(3);
    // cout << endl;
    // n->display();

    // cout << "Start--------------\n";
    // for(int i=0; i<3; i++){
    //     a.insert_at_start(i*2);
    // }
    // a.display();

    return 0;
}

