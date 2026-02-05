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

vector<int> bottomView(TreeNode* root){
    vector<int> ans;
    if(root == NULL) return ans;
    map<int,int> mpp; // horizontal distance, node's value
    queue<pair<TreeNode*,int>> q; // node, horizontal distance
    q.push({root,0});
    
    while(!q.empty()){
        auto p = q.front();
        q.pop();

        TreeNode* node = p.first;
        int line = p.second;
        mpp[line] = node->data; // overwrite the value at horizontal distance

        if(node->left) q.push({node->left, line-1});
        if(node->right) q.push({node->right, line+1});
    }
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
    root->left->left->right = new TreeNode(7);

    vector<int> result = bottomView(root);
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
}
