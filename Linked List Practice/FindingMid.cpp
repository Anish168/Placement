//mid point runner technique

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
    //(n/2)+1 mid hoga even m yha
    // node *slow = head;
    // node *fast = head;

    // while (fast != NULL && fast->next != NULL)
    // {
    //     slow = slow->next;
    //     fast = fast->next->next;
    // }
    // return slow->data;


    //(n/2) mid hoga yha even m

    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    insertatfront(head, tail, 78);
    insertatfront(head, tail, 28);
    insertatfront(head, tail, 41);
    insertatfront(head, tail, 63);
    insertatfront(head, tail, 54);
    insertatfront(head, tail, 100);

    printlinkedlist(head);
    cout << "Mid is " << mid(head) << endl;
    return 0;
}