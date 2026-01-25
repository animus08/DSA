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

int maxDepth(TreeNode* root){
    if(root == NULL) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;

    while(!q.empty()){
        int size = q.size();
        depth++;

        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
    }
    return depth;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "Maximum Depth of Binary Tree: " << maxDepth(root) << endl;
    return 0;
}
