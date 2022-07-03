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

node *uniqueUnsortedList(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *curr = head;

    while (curr != NULL)
    {
        node *temp = curr->next;
        node *prev = curr->next;
        while (temp != NULL)
        {
            if (curr->data == temp->data)
            {
                node *next_next = temp->next;
                node *deletenode = temp;
                delete deletenode;
                temp = next_next;
                prev->next = next_next;
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    insertatfront(head, tail, 78);
    insertatfront(head, tail, 28);
    insertatfront(head, tail, 41);
    insertatfront(head, tail, 41);
    insertatfront(head, tail, 54);
    insertatfront(head, tail, 54);

    printlinkedlist(head);

    uniqueUnsortedList(head);

    printlinkedlist(head);

    return 0;
}