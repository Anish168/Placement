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

node *buildtree()   //return root kr rha h jo node* type ka h so function is node*
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

int main()
{
    node *root = buildtree();

    return 0;
}