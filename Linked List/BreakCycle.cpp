// Cycle to Linear Linked List
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

bool breakCycle(node *head)
{
    node *slow = head;
    node *fast = head;
    node *prev;
    //step1 check cycle is present or not
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    slow = head;        //step 2:- point slow to head
    //step 3:- move both slow and fast pointer by 1 
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
        prev = prev->next;
    }
    //step 4:- at last when the meet again then we put null in the previous pointer
    prev->next=NULL;
}

void createCycle(node *&head, node *&tail)
{
    tail->next = head->next->next;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    int m;
    cin >> m;
    int data;

    for (int i = 0; i <= m - 1; i++)
    {
        cin >> data;
        insertatfront(head, tail, data);
    }
    printlinkedlist(head);

    createCycle(head, tail);

    if (cycleDetection(head))
    {
        cout << "Yes, cycle is present " << endl;
    }
    else
    {
        cout << "No, cycle is not present " << endl;
    }

    createCycle(head, tail);
    breakCycle(head);
    printlinkedlist(head);

    return 0;
}