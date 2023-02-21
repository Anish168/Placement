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

int diameter(node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    // recursive case
    int op1 = diameter(root->left);                                 // case when diameter is pasing through LST
    int op2 = diameter(root->right);                                // case when diameter is pasing through RST
    int op3 = heightoftree(root->left) + heightoftree(root->right); // case when diameter is pasing through Root
    return max(op1, max(op2, op3));                                 // max 2 variable contain krta h issliye andr bhi ek max le liya
                                                                    // ab bracket wale m jo max hoga ushka compare op1 se hoga
}
int main()
{
    node *root = buildtree();
    cout << endl;

    cout << "Preorder print is :- " << endl;
    preorder(root);
    cout << endl;

    cout << "Height of tree is:- " << heightoftree(root) << endl;

    cout << "Diameter of Tree is:- " << diameter(root) << endl;

    return 0;
}