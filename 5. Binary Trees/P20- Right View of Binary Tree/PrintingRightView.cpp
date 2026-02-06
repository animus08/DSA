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

void recursion(TreeNode* root, int level, vector<int> &ans){
    if(root == NULL) return;

    if(ans.size() == level){
        ans.push_back(root->data);
    }

    recursion(root->right, level + 1, ans);
    recursion(root->left, level + 1, ans);
}

vector<int> rightView(TreeNode* root){
    vector<int> ans;
    recursion(root, 0, ans);
    return ans;

}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);

    vector<int> ans = rightView(root);
    cout << "The right view of the binary tree is: ";
    for(int i : ans){
        cout << i << " ";
    }
}
