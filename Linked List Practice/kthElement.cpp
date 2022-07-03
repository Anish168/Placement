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

int mid(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int kthelement(node *head, int k)
{
    node *temp = head;
    node *kth = head;
    for (int i = 0; i < k; i++)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        temp = temp->next;
        kth = kth->next;
    }
    return kth->data;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    int k;
    cin >> k;
    insertatfront(head, tail, 78);
    insertatfront(head, tail, 28);
    insertatfront(head, tail, 41);
    insertatfront(head, tail, 63);
    insertatfront(head, tail, 54);
    insertatfront(head, tail, 100);

    printlinkedlist(head);
    cout << "Kth element is " << kthelement(head, k) << endl;

    return 0;
}