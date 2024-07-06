#include <iostream>
#include "Circular Single Linked List.hh"
#include "Unlimited Stack SLL.hh"
using namespace std;

bool isPalindrome(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty List" << endl;
        return false;
    }
    else if (head->link == NULL)
        return true;
    Node *temp = head;
    Stack s;
    do
    {
        s.PUSH(temp->data);
        temp = temp->link;
    } while (temp != head);
    temp = head;
    do
    {
        if (temp->data != s.POP())
            return false;
        temp = temp->link;
    } while (temp != head);
    return true;
}

int main()
{
    CSL s;
    s.insert_End(1);
    s.insert_End(2);
    s.insert_End(2);
    // s.insert_End(1);

    if (isPalindrome(s.start))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}