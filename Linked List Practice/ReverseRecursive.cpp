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

void reverse(node *&head, node *curr, node *prev)
{
    // base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    // recursive case
    node *n = curr->next;
    reverse(head, n, curr);
    curr->next = prev;
}
node *reverselinkedlist(node *&head)
{
    node *curr = head;
    node *prev = NULL;
    reverse(head, curr, prev);
    return head;
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