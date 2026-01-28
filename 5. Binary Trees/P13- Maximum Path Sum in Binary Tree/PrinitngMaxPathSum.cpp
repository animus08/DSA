#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int maxPathDown(TreeNode* root, int &maxi){
    if(root == NULL) return 0;

    int left = max(0, maxPathDown(root->left, maxi));
    int right = max(0, maxPathDown(root->right, maxi));

    maxi = max(maxi, left + right + root-> data);

    return max(left, right) + root->data;
}

int maxPathSum(TreeNode* root){
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    int maxSum = maxPathSum(root);
    cout << "Maximum Path Sum in the Binary Tree is: " << maxSum << endl;
}
