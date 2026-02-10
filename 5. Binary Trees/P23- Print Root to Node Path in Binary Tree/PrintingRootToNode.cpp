#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

bool getPath(TreeNode* root, vector<int> &ans, int x){
    if(root == NULL)
        return false;

    ans.push_back(root->data);
    
    if(root->data == x)
        return true;

    if(getPath(root->left, ans, x) || getPath(root->right, ans, x))
        return true;

    ans.pop_back();
    return false;
}

vector<int> solve(TreeNode* root, int B){
    vector<int> ans;
    if(root == NULL) return ans;

    getPath(root, ans, B);
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int B;
    cout << "Enter the node value to find path from root: ";
    cin >> B;

    vector<int> ans = solve(root, B);
    if(ans.size() == 0){
        cout << "No path found from root to node " << B << endl;
    } else {
        cout << "Path from root to node " << B << ": ";
        for(int val : ans){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
