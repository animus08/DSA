#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

bool isLeaf(TreeNode *node)
{
    return node && !node->left && !node->right;
}

void leftBoundary(TreeNode* root, vector<int> &ans){
    TreeNode* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void rightBoundary(TreeNode* root, vector<int> &ans){
    TreeNode* curr = root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i = temp.size() - 1; i >= 0; i--){
        ans.push_back(temp[i]);
    }
}

void addLeaves(TreeNode* root, vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left, ans);
    if(root->right) addLeaves(root->right, ans);
}

vector<int> printBoundary(TreeNode* root){
    vector<int> ans;
    if (!root)
        return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    leftBoundary(root, ans);
    addLeaves(root, ans);
    rightBoundary(root, ans);
    return ans;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = printBoundary(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}
