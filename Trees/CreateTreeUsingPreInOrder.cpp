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

int pre[] = {8, 3, 16, 4, 7, 10, 14, 13};
int in[] = {1, 3, 4, 6, 7, 8, 10, 13, 14};
int i = 0;
node *createTree(int start, int end)
{
    // base case
    if (start > end)
    {
        return NULL;
    }

    // recursive case
    int element = pre[i];           // pre k element lega
    node *root = new node(element); // ushko root node bnayega
    i++;
    int k = -1; // k = -1 cuz postive number nhi le rhe index ho jyga
    for (int j = start; j <= end; j++)
    {
        if (in[j] == element) // pre k eelment ko in m find kr rhe
        {
            k = j; // milte hi k m dal denge ushka index
            break;
        }
    }
    root->left = createTree(start, k - 1); // ab jo element humhe in m mila h ushke left k element ko LST m dal denge
    root->right = createTree(k + 1, end);  // ab jo element humhe in m mila h ushke right k element ko RST m dal denge
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
    int n = sizeof(pre) / sizeof(int);
    int start = 0;
    int end = n - 1;
    createTree(start, end);
    return 0;
}