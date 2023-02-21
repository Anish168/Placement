// 3rd way
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
class Pair
{
public:
    int height;
    bool isbalanced;

    Pair()
    {
        height = 0;
        isbalanced = true;
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

Pair isheightbalanced(node *root)
{
    Pair p;
    // base case
    if (root == NULL)
    {
        return p;
    }

    // recursive case
    Pair l = isheightbalanced(root->left);
    Pair r = isheightbalanced(root->right);
    p.height = max(l.height, r.height) + 1;
    if (l.isbalanced == true && r.isbalanced == true && abs(l.height - r.height) <= 1)
    {
        p.isbalanced = true;
    }
    p.isbalanced = false;
}

int main()
{
    node *root = buildbst();
    Pair X = isheightbalanced(root);
    if (X.isbalanced == true)
    {
        cout << "Yes, its balanced";
    }
    else
    {
        cout << "No, its not balanced";
    }

    return 0;
}