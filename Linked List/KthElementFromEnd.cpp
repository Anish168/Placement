#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // parametrized constructor
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
    node *temp = head; // you can use without taking temp cuz head humne pass by refrence nhi kiya pass by value kiya h

    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << endl;
}

node *kthElement(node *head, int key)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *temp = head;
    node *slow = head;
    for (int i = 1; i <= key; i++)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        slow = slow->next;
        temp = temp->next;
    }
    return slow;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    insertatfront(head, tail, 90);  // 90
    insertatfront(head, tail, 63);  // 63-->90
    insertatfront(head, tail, 20);  // 20-->63-->90
    insertatfront(head, tail, 200); // 200-->20-->63-->90
    printlinkedlist(head);

    node *ans = kthElement(head, 1);
    cout << ans->data << endl;

    return 0;
}