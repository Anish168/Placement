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

void printrange(node *root, int key1, int key2)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recurisve case
    // print range in LST
    printrange(root->left, key1, key2);

    // print root data if they exist in between them
    if (root->data >= key1 && root->data <= key2)
    {
        cout << root->data << " ";
    }

    // print range in RST
    printrange(root->right, key1, key2);
}

int main()
{
    node *root = buildbst();
    int key1, key2;
    cin >> key1 >> key2;
    printrange(root, key1, key2);

    return 0;
}