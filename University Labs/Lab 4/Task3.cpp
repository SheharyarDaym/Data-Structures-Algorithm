#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int x = 0) : data(x), prev(NULL), next(NULL) {}
};

class FrontMiddleBack
{
private:
    Node *front;
    Node *rear;

public:
    FrontMiddleBack() : front(NULL), rear(NULL) {}
    void pushFront(int val)
    {
        if (front == NULL)
        {
            front = new Node(val);
            rear = front;
            front->next = rear;
            rear->prev = front;
            front->prev = rear;
            rear->next = front;
        }
        else
        {
            Node *temp = new Node(val);
            temp->next = front;
            front->prev = temp;
            front = temp;
            rear->next = temp;
            temp->prev = rear;
        }
    }

    void pushMiddle(int val)
    {
        if (front == NULL)
        {
            front = new Node(val);
            rear = front;
            front->next = rear;
            rear->prev = front;
            front->prev = rear;
            rear->next = front;
        }
        else
        {
            int s = size();
            s = s / 2;
            int i = 0;
            Node *temp = front;
            while (i != s)
            {
                i++;
                temp = temp->next;
            }
            Node *t = new Node(val);
            temp->prev->next = t;
            t->prev = temp->prev;
            t->next = temp;
            temp->prev = t;
        }
    }

    void pushBack(int val)
    {
        if (front == NULL)
        {
            front = new Node(val);
            rear = front;
            front->next = rear;
            rear->prev = front;
            front->prev = rear;
            rear->next = front;
        }
        else
        {
            Node *temp = new Node(val);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            rear->next = front;
            front->prev = rear;
        }
    }

    int popFront()
    {
        if (front == NULL)
        {
            cout << "empty" << endl;
            return -1;
        }
        else if (front == rear)
        {
            delete front;
            front = NULL;
            rear = NULL;
        }
        int val = front->data;
        Node *t = front;
        front = front->next;
        front->prev = rear;
        rear->next = front;
        delete t;
        return val;
    }

    int popMiddle()
    {
        if (front == NULL)
        {
            cout << "empty" << endl;
            return -1;
        }
        int val;
        if (front == rear)
        {
            val = front->data;
            delete front;
            front = NULL;
            rear = NULL;
        }

        int s = size();
        s = s / 2;
        int i = 0;
        Node *temp = front;
        while (i != s + 1)
        {
            i++;
            temp = temp->next;
        }
        val = temp->data;
        Node *t = temp->prev;
        temp->prev->prev->next = temp;
        temp->prev = temp->prev->prev;
        delete t;
        return val;
    }

    int popBack()
    {
        int val;
        if (front == NULL)
        {
            cout << "Queue is empty! " << endl;
            return -1;
        }
        else if (front == rear)
        {
            val = front->data;
            delete front;
            front = NULL;
            rear = NULL;
        }
        else
        {
            val = rear->data;
            Node *temp = rear;
            rear = rear->prev;
            front->prev = rear;
            rear->next = front;
            delete temp;
        }
        return val;
    }

    int size()
    {
        if (front == NULL)
            return 0;
        int s = 0;
        Node *temp = front;
        do
        {
            s++;
            temp = temp->next;
        } while (temp != front);

        return s;
    }

    void display()
    {
        Node *temp = front;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
    }
};

int main()
{
    FrontMiddleBack f;
    f.pushFront(1);
    f.pushFront(2);
    f.pushFront(3);
    // f.pushFront(4);
    f.pushFront(6);
    // f.pushBack(6);
    f.pushMiddle(5);
    f.display();
    cout << endl;
    f.popMiddle();
    f.popFront();
    f.popBack();
    f.display();
    return 0;
}