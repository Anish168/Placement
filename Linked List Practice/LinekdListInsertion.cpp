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
//-----------------------------------------------------------------------------

void insertattail(node *&head, node *&tail, int data)
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
        tail->next = n;
        tail = n;
    }
}
//------------------------------------------------------------------------------

int lengthlinkedlist(node *head)
{
    node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int lengthlinkedlistrec(node *head)
{
    // base case
    if (head == NULL)
    {
        return 0;
    }

    // recursive case
    return 1 + lengthlinkedlistrec(head->next);
}

void insertatanypos(node *&head, node *&tail, int data, int pos)
{
    node *n = new node(data);
    if (pos == 0)
    {
        insertatfront(head, tail, data);
    }
    else if (pos >= lengthlinkedlist(head))
    {
        insertattail(head, tail, data);
    }
    else
    {
        node *temp = head;
        for (int jump = 1; jump <= pos - 1; jump++)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
}
//-------------------------------------------------------------------------------
// Deletion

void deleteatfront(node *&head, node *&tail)
{
    // empty
    if (head == NULL)
    {
        return;
    }
    // single node
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    // whole linked list present
    else
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteattail(node *&head, node *&tail)
{
    // empty
    if (head == NULL)
    {
        return;
    }
    // single node
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    // whole linkedlist
    else
    {
        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
}

void deleteatanypos(node *&head, node *&tail, int pos)
{
    if (pos == 0)
    {
        deleteatfront(head, tail);
    }

    else if (pos >= lengthlinkedlist(head))
    {
        deleteattail(head, tail);
    }
    else
    {
        node *temp = head;
        node *curr = NULL;
        node *del = NULL;
        for (int jump = 1; jump <= pos - 1; jump++)
        {
            temp = temp->next;
        }
        del = temp->next;
        curr = temp->next->next;
        temp->next = curr;
        delete del;
        del = NULL;
    }
}
// -----------------------------------------------------------------------------------
bool search(node *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

bool searchrec(node *head, int key)
{
    // base case
    if (head == NULL)
    {
        return false;
    }

    // recursive case
    if (head->data == key)
    {
        return true;
    }
    return searchrec(head->next, key);
}

// ---------------------------------------------------------------------------------------
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
int main()
{
    node *head = NULL;
    node *tail = NULL;

    insertatfront(head, tail, 90);
    insertatfront(head, tail, 63);
    insertatfront(head, tail, 20);
    insertatfront(head, tail, 100);

    printlinkedlist(head);

    insertattail(head, tail, 79);
    insertattail(head, tail, 87);

    printlinkedlist(head);

    insertatanypos(head, tail, 54, 0);
    insertatanypos(head, tail, 12, 7);
    insertatanypos(head, tail, 36, 3);

    printlinkedlist(head);

    deleteatfront(head, tail);

    printlinkedlist(head);

    deleteattail(head, tail);

    printlinkedlist(head);

    deleteatanypos(head, tail, 2);

    printlinkedlist(head);

    if (search(head, 100))
    {
        cout << "Yes, it is present " << endl;
    }
    else
    {
        cout << "No, it isn't present " << endl;
    }

    if (searchrec(head, 52))
    {
        cout << "Yes, it is present " << endl;
    }
    else
    {
        cout << "No, it isn't present " << endl;
    }

    return 0;
}