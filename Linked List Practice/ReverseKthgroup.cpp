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

node *reverse(node *&head, int k)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }

    // recursive call
    node *n = NULL;
    node *curr = head;
    node *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    if (n != NULL)
    {
        return head->next = reverse(n, k);
    }
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    insertatfront(head, tail, 90);
    insertatfront(head, tail, 63);
    insertatfront(head, tail, 20);
    insertatfront(head, tail, 100);

    printlinkedlist(head);

    reverse(head, 3);

    printlinkedlist(head);

    return 0;
}