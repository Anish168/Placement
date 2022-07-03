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
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << endl;
}

void reverselinkedlist(node *&head)
{
    node *curr = head;
    node *prev = NULL;
    node *n = NULL;

    while (curr != NULL)
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    head = prev;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;

    insertatfront(head, tail, 90);
    insertatfront(head, tail, 63);
    insertatfront(head, tail, 20);
    insertatfront(head, tail, 100);
    insertatfront(head, tail, 55);

    printlinkedlist(head);

    reverselinkedlist(head);
    
    printlinkedlist(head);

    return 0;
}