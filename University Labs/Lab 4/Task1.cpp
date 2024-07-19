#include<iostream>
using namespace std;

class Patient{ 
friend class Node;
friend class PriorityQueue;
    string name;
    string disorder;
    string registrationNo;
    int severity;
public:
    Patient(string name = "", string disorder = "", string registrationNo = "", int severity = 0){
        this->name = name;
        this->disorder = disorder;
        this->registrationNo = registrationNo;
        this->severity = severity;
    } 
};

class Node{
public:
friend class Patient;
    Patient p;
    int priority;
    Node* link;
    Node(const Patient& patient){
        p = patient;
        priority = patient.severity;
        link = NULL;
    }
    void display(){
        cout << endl;
        cout << "Name: " << p.name << endl;
        cout << "Disorder: " << p.disorder << endl;
        cout << "RegistrationNo: " << p.registrationNo << endl;
        cout << "Severity: " << p.severity << endl << endl;
    }
};

class PriorityQueue{
private:
    Node* front;
    Node* rear;
public:
    PriorityQueue() : front(NULL), rear(NULL) {}
    void enqueue(const Patient& p)
    {
        if(front == NULL){
            front = new Node(p);
            rear = front;
        }
        else if(front->priority > p.severity){
            Node* t = new Node(p);
            t->link = front;
            front = t;
        }
        else{
            Node* temp = front;
            Node* prev = NULL;
            while(temp != NULL && temp->priority <= p.severity){
                prev = temp;
                temp = temp->link;
            }
            Node* t = new Node(p);
            if(temp == NULL){
                rear->link = t;
                rear = t;
            }   
            else{ 
                prev->link = t;
                t->link = temp;                 
            }

        }
    }
    Patient dequeue(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return Patient();
        }
        Node* t = front;
        Patient p = t->p;
        if(front == rear){
            delete front;
            front = NULL;
            rear = NULL;
        }
        else{
            front = front->link;
            delete t;
        }
        return p;
    }

    bool isEmpty(){
        return front == NULL;
    }

    void display(){
        Node* temp = front;
        while(temp != NULL){
            temp->display();
            temp = temp->link;
        }
        cout << endl;
    }
};

class EmergencyRoom{
private: 
    PriorityQueue erQueue;
public:
    void addPatient(const Patient& patient){
        erQueue.enqueue(patient);
    }

    Patient treatNextPatient(){
        return erQueue.dequeue();
    }

    bool hasPatients(){
        if(erQueue.isEmpty()) return false;
        return true;
    }

    void displayAllPatients(){
        erQueue.display();
    }
};

int main()
{
    Patient a("Rafay", "HeartAttack", "44", 2);
    Patient b("Ahmad", "Cancer", "46", 1);
    Patient c("Ali", "Malaria", "41", 4);
    Patient d("Subhan", "Fever", "23", 3);
    
    EmergencyRoom room;
    room.addPatient(a);
    room.addPatient(b);
    room.addPatient(c);
    room.addPatient(d);
    room.treatNextPatient();
    room.displayAllPatients();
    cout << "Has Patients: " << room.hasPatients();

    return 0;
}
#include<iostream>
using namespace std;

class Patient{ 
friend class Node;
friend class PriorityQueue;
    string name;
    string disorder;
    string registrationNo;
    int severity;
public:
    Patient(string name = "", string disorder = "", string registrationNo = "", int severity = 0){
        this->name = name;
        this->disorder = disorder;
        this->registrationNo = registrationNo;
        this->severity = severity;
    } 
};

class Node{
public:
friend class Patient;
    Patient p;
    int priority;
    Node* link;
    Node(const Patient& patient){
        p = patient;
        priority = patient.severity;
        link = NULL;
    }
    void display(){
        cout << endl;
        cout << "Name: " << p.name << endl;
        cout << "Disorder: " << p.disorder << endl;
        cout << "RegistrationNo: " << p.registrationNo << endl;
        cout << "Severity: " << p.severity << endl << endl;
    }
};

class PriorityQueue{
private:
    Node* front;
    Node* rear;
public:
    PriorityQueue() : front(NULL), rear(NULL) {}
    void enqueue(const Patient& p)
    {
        if(front == NULL){
            front = new Node(p);
            rear = front;
        }
        else if(front->priority > p.severity){
            Node* t = new Node(p);
            t->link = front;
            front = t;
        }
        else{
            Node* temp = front;
            Node* prev = NULL;
            while(temp != NULL && temp->priority <= p.severity){
                prev = temp;
                temp = temp->link;
            }
            Node* t = new Node(p);
            if(temp == NULL){
                rear->link = t;
                rear = t;
            }   
            else{ 
                prev->link = t;
                t->link = temp;                 
            }

        }
    }
    Patient dequeue(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return Patient();
        }
        Node* t = front;
        Patient p = t->p;
        if(front == rear){
            delete front;
            front = NULL;
            rear = NULL;
        }
        else{
            front = front->link;
            delete t;
        }
        return p;
    }

    bool isEmpty(){
        return front == NULL;
    }

    void display(){
        Node* temp = front;
        while(temp != NULL){
            temp->display();
            temp = temp->link;
        }
        cout << endl;
    }
};

class EmergencyRoom{
private: 
    PriorityQueue erQueue;
public:
    void addPatient(const Patient& patient){
        erQueue.enqueue(patient);
    }

    Patient treatNextPatient(){
        return erQueue.dequeue();
    }

    bool hasPatients(){
        if(erQueue.isEmpty()) return false;
        return true;
    }

    void displayAllPatients(){
        erQueue.display();
    }
};

int main()
{
    Patient a("Rafay", "HeartAttack", "44", 2);
    Patient b("Ahmad", "Cancer", "46", 1);
    Patient c("Ali", "Malaria", "41", 4);
    Patient d("Subhan", "Fever", "23", 3);
    
    EmergencyRoom room;
    room.addPatient(a);
    room.addPatient(b);
    room.addPatient(c);
    room.addPatient(d);
    room.treatNextPatient();
    room.displayAllPatients();
    cout << "Has Patients: " << room.hasPatients();

    return 0;
}
