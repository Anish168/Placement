// mid point runner techniques
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

int lengthofll(node *head)
{
    int cnt = 0;
    node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

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

int mid(node *head)
{
    node *slow = head;
    // node *fast = head;               //50-->70-->200-->20-->63-->90--> we get 20 as a mid
    node *fast = head->next; // 50-->70-->200-->20-->63-->90-->  we get 200 as a mid means mid is n/2

    // for odd linked list
    // while (fast->next != NULL)
    // {
    //     slow = slow->next;
    //     fast = fast->next->next;
    // }

    // for both  linked list odd and even

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
    insertatfront(head, tail, 90);
    insertatfront(head, tail, 63);
    insertatfront(head, tail, 20);
    insertatfront(head, tail, 200);
    insertatfront(head, tail, 70);
    insertatfront(head, tail, 50);
    printlinkedlist(head);
    cout << endl;
    cout << mid(head);
    return 0;
}