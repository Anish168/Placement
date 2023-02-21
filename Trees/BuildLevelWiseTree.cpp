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

node *buildtree() // return root kr rha h jo node* type ka h so function is node*
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

// Building a Tree in Level wise

node *buildLevel() // return root kr rha h jo node* type ka h so function is node*
{
    node *root = NULL; // first root m null rhega
    int data;
    cin >> data; // data liya jyga
    if (data == -1)
    {
        return NULL;
    }

    root = new node(data); // 1st input ka data lega and node constructor call hoga
    queue<node *> q;       // queue bna h node * type ka cuz root node* type ka h
    q.push(root);

    while (!q.empty()) // tb tk chlega jb tk q empty nhi h
    {
        node *x = q.front(); // queue ka 1st means front lega
        q.pop();             // pop krega

        cout << "Enter children of " << x->data << endl;

        int leftchild, rightchild;
        cin >> leftchild >> rightchild;

        if (leftchild != -1) // agar input -1 nhi h mtlb left child exist krta h ish X ka
        {
            x->left = new node(leftchild); // leftchild ek new node hoga jo x k left m jyga
            q.push(x->left);
        }

        if (rightchild != -1) // agar input -1 nhi h mtlb right child exist krta h ish X ka
        {
            x->right = new node(rightchild); // rightchild ek new node hoga jo x k right m jyga
            q.push(x->right);
        }
    }
    return root;
}

// Print Levelwise
// It's an Algorithm

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
            if (x->right != NULL) // if ayga idhar not else if and it denotes kya x k left child exit krte h
            {
                q.push(x->right);
            }
        }
    }
}

int main()
{
    node *root = buildLevel();
    cout << endl;
    levelorder(root);

    return 0;
}