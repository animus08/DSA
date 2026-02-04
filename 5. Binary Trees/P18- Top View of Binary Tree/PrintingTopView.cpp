#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> topView(TreeNode* root){
    vector<int> ans;
    if(root == NULL) return ans;

    map<int, int> mpp;
    queue<pair<TreeNode*, int>> q; // Pair of node and its horizontal distance
    q.push({root, 0}); // Start with the root at horizontal distance 0

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        TreeNode* node = it.first;
        int line = it.second;

        // If this horizontal distance is not already in the map, add it
        if(mpp.find(line) == mpp.end()){
            mpp[line] = node->data;
        }

        // Traverse left and right children
        if(node->left){
            q.push({node->left, line - 1}); // Left child at horizontal distance -1
        }
        if(node->right){
            q.push({node->right, line + 1}); // Right child at horizontal distance +1
        }
    }

    // Extract the values from the map in sorted order of horizontal distance
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> result = topView(root);
    
    cout << "Top View of the Binary Tree: ";
    for(int val : result){
        cout << val << " ";
    }
}
