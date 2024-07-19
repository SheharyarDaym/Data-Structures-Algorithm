#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d = 0)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class PriorityQueue
{
    Node *front;
    Node *rear;

public:
    PriorityQueue()
    {
        front = NULL;
        rear = NULL;
    }

    ~PriorityQueue()
    {
        Node *temp = front;
        while (!isEmpty())
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }

    bool isEmpty()
    {
        return (front == NULL && rear == NULL);
    }

    void enqueue(int d)
    {
        Node *newNode = new Node(d);
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else if (front->data > d)
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        else
        {
            Node *temp = front;
            while (temp->next != NULL && temp->next->data <= d)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;

            if (temp->next != NULL)
            {
                temp->next->prev = newNode;
            }
            if (temp == rear)
            {
                rear = newNode;
            }
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -999;
        }
        else
        {
            Node *temp = front;
            int dequeued = temp->data;
            if (front == rear)
            {
                front = NULL;
                rear = NULL;
            }
            else
            {
                front->prev = NULL;
                front = front->next;
            }
            delete temp;
            return dequeued;
        }
    }

    int peekFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -999;
        }
        return front->data;
    }

    int peekRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -999;
        }
        return rear->data;
    }

    int size()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return 0;
        }
        else
        {
            int count = 0;
            Node *temp = front;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};


int *merge(int arr1[], int arr2[], int n, int m)
{
    int size = m + n;
    int *arr3 = new int[size];

    PriorityQueue q1;
    for (int i = 0; i < n; i++)
    {
        q1.enqueue(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        q1.enqueue(arr2[i]);
    }

    for (int i = 0; i < size; i++)
    {
        arr3[i] = q1.dequeue();
    }

    return arr3;
}


void input(int *arr, int size)
{
    cout << "Enter array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    int n, m;
    cout << "Enter sizes 1 and 2: ";
    cin >> n >> m;
    int *arr1 = new int[n];
    input(arr1, n);
    int *arr2 = new int[m];
    input(arr2, m);
    int *a = merge(arr1, arr2, n, m);
    for (int i = 0; i < n + m; i++)
    {
        cout << a[i] << " ";
    }

    delete[] arr1;
    delete[] arr2;
    delete[] a;
    arr1 = nullptr;
    arr2 = nullptr;
    a = nullptr;
    return 0;
}
