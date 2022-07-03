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

node *mergetwosortedlinkedlist(node *head1, node *head2)
{
    // base case
    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }

    // recursive case

    node *newhead;
    if (head1->data < head2->data)
    {
        newhead = head1;
        newhead->next = mergetwosortedlinkedlist(head1->next, head2);
    }
    else
    {
        newhead = head2;
        newhead->next = mergetwosortedlinkedlist(head1, head2->next);
    }
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    node *tail1 = NULL;
    node *tail2 = NULL;

    int data;

    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> data;
        insertatfront(head1, tail1, data);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> data;
        insertatfront(head2, tail2, data);
    }

    node *finalans = mergetwosortedlinkedlist(head1, head2);

    printlinkedlist(finalans);
    return 0;
}