node *deleteinbst(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    // key is smaller than root->data
    else if (key < root->data)
    {
        root->left = deleteinbst(root->left, key);
        return root;
    }
    // key is greater than root->data
    else if (key > root->data)
    {
        root->right = deleteinbst(root->right, key);
        return root;
    }
    else
    {
        // root->data==key
        // case 1
        // no child exist
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // case 2 1 part
        // single child exist only rc
        else if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // case 2 2 part
        // single child exist only lc
        else if (root->right == NULL && root->left != NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // case 3
        // rc lc exist
        else
        {
            // // replace min in rst
            node *replace = root->right;
            // loop
            while (replace->left != NULL)
            {
                replace = replace->left;
            }
            swap(root->data, replace->data);
            root->right = deleteinbst(root->right, key);
            return root;
        }
    }
}