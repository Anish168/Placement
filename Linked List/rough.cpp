#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // parametrized constructor
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
void insertatfront(node *&head, node *&tail, int data)
{
    node *n = new node(data);
    if (head == NULL)
    {
        head = n;
        tail = n;
        return;
    }
    else
    {
        n->next = head;
        head = n;
    }
}

void printlinkedlist(node *head)
{
    node *temp = head; // you can use without taking temp cuz head humne pass by refrence nhi kiya pass by value kiya h

    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << endl;
}

bool cycleDetection(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {

        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

void printcycle(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void createCycle(node *&head, node *&tail, int data)
{
    node *n = new node(data);
    if (head == NULL)
    {
        head = n;
        tail = n;
        n->next=n;
    }
    else
    {
        tail->next = n;
        tail = n;
    }
    n=head;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    createCycle(head, tail, 4);
    createCycle(head, tail, 15);
    createCycle(head, tail, 7);
    createCycle(head, tail, 40);
    printcycle(head);
    return 0;
}