#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root){
    map<int, map<int, vector<int>>> nodes;      // If using vector then we have to sort at last.
    queue<pair<TreeNode*, pair<int, int>>> todo;
    todo.push({root, {0,0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second;

        nodes[x][y].push_back(node->data);

        if(node->left) todo.push({node->left, {x-1, y+1}});
        if(node->right) todo.push({node->right, {x+1, y+1}});
    }
    vector<vector<int>> ans;
    for(auto p : nodes){
        vector<int> col;
        for(auto q : p.second){
            sort(q.second.begin(), q.second.end()); // Sort the values at the same position
            // If using multiset in place of vector above, then we can directly insert without sorting.
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->right = new TreeNode(7);

    vector<vector<int>> result = verticalTraversal(root);
    for(const auto& col : result){
        for(int val : col){
            cout << val << " ";
        }
        cout << endl;
    }
}
