#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
node *insertinbst(int data, node *root)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (data <= root->data)
    {
        root->left = insertinbst(data, root->left);
        return root;
    }
    else
    {
        root->right = insertinbst(data, root->right);
        return root;
    }
}
node *buildbst()
{
    node *root = NULL;
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertinbst(data, root);
        cin >> data;
    }
    return root;
}

// Converting Binary Search Tree in Sorted Linked List
class LinkedList
{
public:
    node *head;
    node *tail;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
};

LinkedList bsttoll(node *root)
{
    LinkedList l;
    // base case
    if (root == NULL)
    {
        // return l;
        l.head = root;
        l.tail = root;
    }

    // recursive case
    // case 1:- Both left and right doesn't exit
    if (root->left == NULL && root->right == NULL)
    {
        l.head = root;
        l.tail = root;
        // return l;
    }
    // case 2:- Left exit but right don't exit
    else if (root->left != NULL && root->right == NULL)
    {
        LinkedList x = bsttoll(root->left);
        x.tail->right = root;
        l.head = x.head;
        l.tail = root;
        // return l;
    }
    // case 3:- Right exit but left don't exit
    else if (root->left == NULL && root->right != NULL)
    {
        LinkedList y = bsttoll(root->right);
        root->right = y.head;
        l.head = root;
        l.tail = y.tail;
        // return l;
    }
    // case 4:- left exit and right exit
    else
    {
        LinkedList x = bsttoll(root->left);
        LinkedList y = bsttoll(root->right);
        x.tail->right = root;
        root->right = y.head;
        l.head = x.head;
        l.tail = y.tail;
        // return l;
    }
    return l;
}

void levelorder(node *root)
{
    // take a queue of type node*
    queue<node *> q;

    // push root node
    q.push(root);

    // push null
    q.push(NULL);

    while (!q.empty()) // jb tk empty nhi h
    {
        node *x = q.front(); // queue ka Ist nikalega
        q.pop();

        if (x == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << x->data << " "; // x ek pointer so ponter k thorugh bucket use krna h isslie arrow
            if (x->left != NULL)    // kya x k left child exit krte h
            {
                q.push(x->left); // address jyga left ka
            }
            if (x->right != NULL) // kya x k left child exit krte h
            {
                q.push(x->right);
            }
        }
    }
}

void printLinkedlist(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main()
{
    node *root = buildbst();
    levelorder(root);
    LinkedList l = bsttoll(root);
    printLinkedlist(l.head);
    return 0;
}