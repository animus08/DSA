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

int getHeight(TreeNode* root){
    if (root == NULL) return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode* root){
    if (root == NULL) return true;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    if(abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
        return true;
    }
    return false;
    
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    if (isBalanced(root)) {
        cout << "The binary tree is balanced." << endl;
    }
    else {
        cout << "The binary tree is not balanced." << endl;
    }
}
