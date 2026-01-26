#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int dfsHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = dfsHeight(root->left);
    if(lh == -1) return -1; // Left subtree is not balanced

    int rh = dfsHeight(root->right);
    if(rh == -1) return -1; // Right subtree is not balanced

    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode *root)
{
    return dfsHeight(root) != -1;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    if (isBalanced(root))
    {
        cout << "The binary tree is balanced." << endl;
    }
    else
    {
        cout << "The binary tree is not balanced." << endl;
    }
}
