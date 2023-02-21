// mlttn=maximum level traverse till now
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
    root->left = buildtree();
    root->right = buildtree();
    return root;
}

void rightview(node *root, int level, int &mlttn)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive case
    if (level > mlttn)
    {
        cout << root->data << " ";
        mlttn = level;
    }
    rightview(root->right, level + 1, mlttn);
    rightview(root->left, level + 1, mlttn);
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
node *createbstusingsortedarray(int *arr, int s, int e)
{
    // base case
    if (s > e)
    {
        return NULL;
    }

    // recursive case
    int mid = (s + e) / 2;
    node *root = new node(arr[mid]);
    root->left = createbstusingsortedarray(arr, s, mid - 1);
    root->right = createbstusingsortedarray(arr, mid + 1, e);
    return root;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);
    node *root = createbstusingsortedarray(arr, 0, n - 1);
    levelorder(root);
    cout << endl;
    cout << "Right View" << endl;
    int x = 0;
    // rightview(root, 1, 0); // pass by reference m direct value pass nhi kr skte issliye kisi variable k through pass krenge
    rightview(root,1,x);
    return 0;
}