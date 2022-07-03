#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    // constructor
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
// Insert at front
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
//-----------------------------------------------------------------------------
void printlinkedlist(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << endl;
}

breakCycle(node*head)
{
    //Step 1:- cycle present is not
    
}
void cycleCreate(node *&head, node *&tail,int k)
{
    tail->next = head->next->next;
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
int main()
{
    node *head = NULL;
    node *tail = NULL;

    insertatfront(head, tail, 8);
    insertatfront(head, tail, 7);
    insertatfront(head, tail, 6);
    insertatfront(head, tail, 5);
    insertatfront(head, tail, 4);
    insertatfront(head, tail, 3);
    insertatfront(head, tail, 2);
    insertatfront(head, tail, 1);

    printlinkedlist(head);

    cycleCreate(head, tail);

    if (cycleDetection(head))
    {
        cout << "Yes it is present " << endl;
    }
    else
    {
        cout << "No it is not present " << endl;
    }

    return 0;
}