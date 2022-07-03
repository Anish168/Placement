#include <iostream>
#include <list>
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
    }
    else
    {
        n->next = head;
        head = n;
    }
}

void printlinkedlist(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << endl;
}

node *uniqueSortedList(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *curr = head;
    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data)) // if both are same
        {
            node *next_next = curr->next->next;
            node *deleteNode = curr->next;
            delete deleteNode;
            curr->next = next_next;
        }
        else // both are not same
        {
            curr = curr->next;
        }
    }
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    insertatfront(head, tail, 2);
    insertatfront(head, tail, 2);
    insertatfront(head, tail, 5);
    insertatfront(head, tail, 7);
    insertatfront(head, tail, 7);
    insertatfront(head, tail, 10);

    printlinkedlist(head);

    uniqueSortedList(head);

    printlinkedlist(head);

    return 0;
}