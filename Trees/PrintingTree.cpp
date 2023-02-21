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

// Inorder Print
void inorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recurisve case
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Print
void postorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recurisve case
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = buildtree();
    cout << endl;

    cout << "Preorder print is :- " << endl;
    preorder(root);
    cout << endl;

    cout << "Inoreder Print is :- " << endl;
    inorder(root);
    cout << endl;

    cout << "Postoreder Print is :- " << endl;
    postorder(root);

    return 0;
}