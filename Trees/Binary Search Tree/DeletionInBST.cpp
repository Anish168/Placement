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
node *buildtree()
{
    int data;
    cin >> data;

    // terimnation or base case
    if (data == -1)
    {
        return NULL;
    }

    node *root = new node(data);
    root->left = buildtree();
    root->right = buildtree();
    return root;
}

node *deleteinbst(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    // key is smaller than root->data
    else if (key < root->data)
    {
        root->left = deleteinbst(root->left, key);
        return root;
    }
    // key is greater than root->data
    else if (key > root->data)
    {
        root->right = deleteinbst(root->right, key);
        return root;
    }
    // if key is root->data
    else
    {
        // case 1: single node h
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // case 2: Right child-: ek child exist krta h eg Right child bs exit krta h
        else if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // case 2: Left child-: ek child exist krta h eg Left child bs exit krta h
        else if (root->right == NULL && root->left != NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // case 3: Both child exist
        else
        {
            // replace min in rst
            node *replace = root->right;
            while (replace->left != NULL)
            {
                replace = replace->left; // Rst ka minimum element
            }
            swap(root->data, replace->data);             // Rst k minimum element k saath swap krna h
            root->right = deleteinbst(root->right, key); // delete root k right isslie kia kyuki humhe pta h wo mera data jo h wo right tree m exit krta h
            return root;
        }
    }
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
node *createbstusingsortedarray(int *arr, int s, int e)
{
    // base case
    if (s > e)
    {
        return NULL;
    }

    // recursive case
    int mid = (s + e) / 2;
    node *root = new node(arr[mid]);
    root->left = createbstusingsortedarray(arr, s, mid - 1);
    root->right = createbstusingsortedarray(arr, mid + 1, e);
    return root;
}
node *insertInBST(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertInBST(root->right, data);
        return root;
    }
    else
    {
        root->left = insertInBST(root->left, data);
        return root;
    }
}
node *binarySearchTree()
{
    node *root = NULL;
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertInBST(root, data);
        cin >> data;
    }
    return root;
}
int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 8, 9, 10};
    // int n = sizeof(arr) / sizeof(int);
    // node *root = createbstusingsortedarray(arr, 0, n - 1);
    node*root=binarySearchTree();
    levelorder(root);

    root = deleteinbst(root, 8);
    cout << "After deletion" << endl;
    levelorder(root);

    // cout << "After deletion of root node" << endl;
    // root = deleteinbst(root, 4);
    // levelorder(root);
    return 0;
}