// Codehelp Insertion
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
        this->next = NULL;
    }

    // destructor
    ~node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

// Insert at head

void insertAtHead(node *&head, int d)
{
    // creating new node
    node *temp = new node(d); // Step 1
    temp->next = head;        // Step 2
    head = temp;              // Step 3
}

// InsertAt Tail

void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp; // tail = tail->next;
}

// InsertAtPos

void insertAtPos(node *&head, node *&tail, int position, int d)
{
    // insert at starting
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    // insert at any position
    node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // // insert at last
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a node
    node *nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

// Printing

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "--->";
        temp = temp->next;
    }
    cout << endl;
}

// Deleting a node

void deleteNode(int position, node *&head)
{
    // deleting first or start node
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        // memory free start node
        temp->next=NULL;
        delete temp;
    }

    // any node deleting
    node *curr = head;
    node *prev = NULL;
    int cnt = 1;
    while (cnt <= position)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main()
{
    // creating a new node
    node *node1 = new node(7); // Heap m node1 create hoga
    // head pointed to node 1;
    node *tail = node1;
    node *head = node1;
    insertAtTail(tail, 5);
    insertAtTail(tail, 9);

    insertAtPos(head, tail, 3, 22);
    print(head);

    deleteNode(1, head);
    print(head);

    return 0;
}