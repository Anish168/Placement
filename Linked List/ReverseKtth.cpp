//nhi hua
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

void inesertatfront(node *&head, node *&tail, int data)
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

void deleteatfront(node *&head, node *&tail)
{
    if (head == NULL)
    {
        return;
    }

    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }

    else
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

node *reverse(node *head, int key)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }

    // Step 1:
    node *curr = NULL;
    node *prev = NULL;
    node *n;
    int cnt = 1;

    // Step 2: Alogrithm for
    while (curr != NULL && cnt <= key)
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
        cnt++;
    }

    // Step 3: Recursion
    if (n != NULL)
    {
        head->next = reverse(head, key);
    }
    return head;
}

void printlinkedlist(node *head)
{
    node *temp = head; // you can use without taking temp cuz head humne pass by refrence nhi kiya pass by value kiya h

    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    inesertatfront(head, tail, 90);
    inesertatfront(head, tail, 63);
    inesertatfront(head, tail, 20);
    inesertatfront(head, tail, 200);
    printlinkedlist(head);

    reverse(head, 2);
    printlinkedlist(head);
}