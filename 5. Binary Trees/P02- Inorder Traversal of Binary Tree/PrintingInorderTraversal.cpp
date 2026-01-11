#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
}
