#include <iostream>
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
    root->left = buildtree();  // expect ki yeh humhe LST ka address dega jishe hum root k Left m dalenge
    root->right = buildtree(); // expect ki yeh humhe RST ka address dega jishe hum root k Right m dalenge
    return root;
}

// Preorder Print
void preorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive case
    cout << root->data << " ";
    preorder(root->left);  // LST
    preorder(root->right); // RST
}

int heightoftree(node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    // recursive case
    int Lst = heightoftree(root->left);  // recursion left subtree ka height dega
    int Rst = heightoftree(root->right); // recursion right subtree ka height dega
    return max(Lst, Rst) + 1;            // un dono m jo maximum height h wo + 1 jo root level
}
int main()
{
    node *root = buildtree();
    cout << endl;

    cout << "Preorder print is :- " << endl;
    preorder(root);
    cout << endl;

    cout << "Height of tree is:- " << heightoftree(root) << endl;
    return 0;
}