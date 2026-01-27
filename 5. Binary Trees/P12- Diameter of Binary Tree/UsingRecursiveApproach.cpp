#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int findLeftHeight(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + findLeftHeight(root->left);
}

int findRightHeight(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + findRightHeight(root->right);
}

int findMax(TreeNode* root){
    int maxi = 0;
    if(root == NULL) return 0;

    int lh = findLeftHeight(root->left);
    int rh = findRightHeight(root->right);

    maxi = max(maxi, lh + rh);

    findMax(root->left);
    findMax(root->right);

    return maxi;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    int diameter = findMax(root);
    cout << "Diameter of the binary tree is: " << diameter << endl;
}
