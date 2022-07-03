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

// finding length recursively

int length(node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    return 1 + length(head->next);
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

void insertatanypos(node *&head, node *&tail, int data, int pos)
{
    if (pos == 0)
    {
        insertatfront(head, tail, data);
        return;
    }

    else if (pos >= lengthofll(head))
    {
        insertattail(head, tail, data);
        return;
    }
    else
    {
        node *temp = head;
        for (int jump = 1; jump <= pos - 1; jump++)
        {
            temp = temp->next;
        }
        node *n = new node(data);
        n->next = temp->next; // phle rHS evalauta hota h
        temp->next = n;
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

//--------------------------------------------------------------------------------------------------------------------------

// Delete

void deleteatfront(node *&head, node *&tail)
{
    // linkedlist empty
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

    // full linked list
    else
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteattail(node *&head, node *tail)
{
    // linkedlist empty
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

//---------------------------------------------------------------------------------------------------------------------

// Searching
bool searchiterative(node *head, int key)
{
    // traverseing linked list
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

    if (head->data == key)
    {
        return true;
    }
    searchrec(head->next, key);
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    // userdefined Linked List
    //  int data;
    //  cin>>data;
    //  insertatfront(head,tail,data);

    insertatfront(head, tail, 90);  //90
    insertatfront(head, tail, 63);  //63 90
    insertatfront(head, tail, 20);  //20 63 90

    insertattail(head, tail, 79);   //20 63 90 79
    insertattail(head, tail, 47);   //20 63 90 79 47

    insertatanypos(head, tail, 700, 0); // first    700 20 63 90 79 47
    insertatanypos(head, tail, 21, 8);  // last     700 20 63 90 79 47 21
    insertatanypos(head, tail, 32, 3);  //          700 20 63 3 90 79 47 21
    printlinkedlist(head);

    deleteatfront(head, tail);          // 20 63 3 90 79 47 21
    printlinkedlist(head);

    deleteattail(head, tail);           // 20 63 3 90 79 47
    printlinkedlist(head);

    if (searchiterative(head, 21))
    {
        cout << "Yes, Key is present" << endl;
    }
    else
    {
        cout << "No, Key is not present" << endl;
    }

    if (searchrec(head, 20))
    {
        cout << "Yes, Key is present" << endl;
    }
    else
    {
        cout << "No, Key is not present" << endl;
    }

    return 0;
}