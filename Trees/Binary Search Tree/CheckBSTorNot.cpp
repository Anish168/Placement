//3rd way
#include <iostream>
#include <queue>
#include <limits.h>
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

bool isbst(node *root, int min = INT_MIN, int max = INT_MAX)
{
    // base case
    if (root == NULL)
    {
        return true;
    }

    // recurisve case
    if (root->data >= min && root->data < max && isbst(root->left, min, root->data) && isbst(root->right, root->data, max))
    {
        return true;
    }
    return false;
}

int main()
{
    node *root = buildtree();
    if (isbst(root))
    {
        cout << "Yes, Its bst" << endl;
    }
    else
    {
        cout << "No, Its not bst" << endl;
    }

    return 0;
}