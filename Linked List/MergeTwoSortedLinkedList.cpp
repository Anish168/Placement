#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
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
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << endl;
}
node *mergeteosortedarray(node *h1, node *h2)
{
    // base case
    if (h1 == NULL)
    {
        return h2;
    }

    if (h2 == NULL)
    {
        return h1;
    }

    // recursive case
    node *newhead;
    if (h1->data < h2->data)
    {
        newhead = h1;
        newhead->next = mergeteosortedarray(h1->next, h2);
    }
    else
    {
        newhead = h2;
        newhead->next = mergeteosortedarray(h1, h2->next);
    }
    return newhead;
}

int main()
{
    node *h1 = NULL;
    node *t1 = NULL;
    node *h2 = NULL;
    node *t2 = NULL;

    int m, n;
    cin >> m >> n;
    int data;

    for (int i = 0; i < m - 1; i++)
    {
        cin >> data;
        insertatfront(h1, h2, data);
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> data;
        insertatfront(h1, h2, data);
    }
    
    node *final = mergeteosortedarray(h1, h2);
    printlinkedlist(final);
    return 0;
}