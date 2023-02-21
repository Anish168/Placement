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

int countNode(node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    // recursive case
    return countNode(root->left) + countNode(root->right) + 1;      //0+0+1=1; 1+3+1=4; 
}
int main()
{
    node *root = buildtree();
    cout << endl;

    cout << "Preorder print is :- " << endl;
    preorder(root);
    cout << endl;

    cout<<"Count of node is:- "<<countNode(root)<<endl;
    return 0;
}