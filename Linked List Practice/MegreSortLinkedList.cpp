#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    //
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

int lengthofll(node *head)
{
    node *temp = head;
    int co = 0;

    // loop
    while (temp != NULL)
    {
        co++;              // 6
        temp = temp->next; // 1000
    }
    return co;
}

void printlinkedlist(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->"; // 20
        head = head->next;           // 1900
    }
    cout << endl;
}

node *mid(node *head)
{
    node *slow = head;
    node *fast = head->next;
    // loop
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void reversell(node *&head)
{
    node *curr = head;
    node *prev = NULL;
    node *n;

    // loop
    while (curr != NULL)
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    head = prev;
}

node *mergetwosortedll(node *h1, node *h2)
{
    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }

    // recursive
    node *newhead;
    if (h1->data < h2->data)
    {
        newhead = h1;
        newhead->next = mergetwosortedll(h1->next, h2);
    }
    else
    {
        newhead = h2;
        newhead->next = mergetwosortedll(h1, h2->next);
    }
    return newhead;
}

node *mergesort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *m = mid(head);
    node *l1h = head;
    node *l2h = m->next;
    m->next = NULL;

    l1h = mergesort(l1h);
    l2h = mergesort(l2h);
    node *fans = mergetwosortedll(l1h, l2h);
    return fans;
}

int main()
{

    node *h1 = NULL;
    node *t1 = NULL;
    int n;
    cin >> n;
    int data;

    for (int i = 0; i < n; i++)
    {
        cin >> data;
        insertatfront(h1, t1, data); // 5 4 3 2 1
    }

    printlinkedlist(h1);

    node *finalans = mergesort(h1);
    printlinkedlist(finalans);
    return 0;
}