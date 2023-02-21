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

bool searchinbst(node *root, int key)
{
    // base case
    if (root == NULL)
    {
        return false;
    }

    // recurisve case
    if (key == root->data)
    {
        return true;
    }

    else if (key < root->data)
    {
        return searchinbst(root->left, key);
    }
    else
    {
        return searchinbst(root->right, key);
    }
}

int main()
{
    node *root = buildbst();
    int key;
    cin>>key;
    if (searchinbst(root,key))
    {
        cout << "Yes, key is present" << endl;
    }
    else
    {
        cout << "No, Key is not present" << endl;
    }
    return 0;
}