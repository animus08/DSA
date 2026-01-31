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

vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    queue <TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while(!nodesQueue.empty()){
        int size = nodesQueue.size();
        vector<int> row(size);

        for(int i = 0; i < size; i++){
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            // Find the position to fill in the row
            // int index = leftToRight ? i : size - 1 - i;
            int index;
            if (leftToRight == true) {
                index = i; // left to right
            }
            else{
                index = size - 1 - i; // right to left
            }
            
            row[index] = node->data;
            if(node->left) nodesQueue.push(node->left);
            if(node->right) nodesQueue.push(node->right);
        }
        ans.push_back(row);
        leftToRight = !leftToRight; // Toggle the direction for the next level
    }
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

    vector<vector<int>> result = zigzagLevelOrder(root);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
