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

int main()
{
    node *root = buildbst();
    levelorder(root);
    return 0;
}