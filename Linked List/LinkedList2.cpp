// Codehelp Insertion
#include <iostream>
using namespace std;

// Creation of Node
/*
class node
{
public:
    int data;
    node *next;

    //constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int main()
{
    node *node1 = new node(20); // Heap m node1 create hoga
    cout << node1->data << endl;
    cout << node1->next << endl;

    return 0;
}
*/

// --------------------------------------------------------------------------------------------------

// InsertionAtHead
// class node
// {
// public:
//     int data;
//     node *next;

//     // constructor
//     node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// /*
// // InsertingAtHead
// void insertAtHead(node* &head, int d)
// {
//     // creating new node
//     node *temp = new node(d); // Step 1
//     temp->next = head;        // Step 2
//     head = temp;              // Step 3
// }

// // Printing
// void print(node* &head)
// {
//     node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << "--->";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main()
// {
//     // node *head = NULL;
//     // insertAtHead(head, 5);
//     // insertAtHead(head, 9);
//     // print(head);

//     // creating a new node
//     node *node1 = new node(7); // Heap m node1 create hoga
//     // head pointed to node 1;
//     node *head = node1;
//     insertAtHead(head, 5);
//     insertAtHead(head, 9);
//     print(head);

//     return 0;
// }
// */

// // InsertAt Tail
// void insertAtTail(node *&tail, int d)
// {
//     node *temp = new node(d);
//     tail->next = temp;
//     tail = temp; // tail = tail->next;
// }

// void print(node *&head)
// {
//     node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << "--->";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main()
// {
//     // creating a new node
//     node *node1 = new node(7); // Heap m node1 create hoga
//     // head pointed to node 1;
//     node *tail = node1;
//     node *head = node1;
//     insertAtTail(tail, 5);
//     insertAtTail(tail, 9);
//     print(head);

//     return 0;
// }

// -------------------------------------------------------------------------------------------------------

// InsertAtAnyPostion

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

int main()
{
    // creating a new node
    node *node1 = new node(7); // Heap m node1 create hoga
    // head pointed to node 1;
    node *tail = node1;
    node *head = node1;
    insertAtTail(tail, 5);
    insertAtTail(tail, 9);
    print(head);

    insertAtPos(head, tail, 3, 22);
    print(head);
    insertAtPos(head, tail, 1, 99);
    print(head);
    insertAtPos(head, tail, 6, 50);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    insertAtTail(tail, 65);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    return 0;
}