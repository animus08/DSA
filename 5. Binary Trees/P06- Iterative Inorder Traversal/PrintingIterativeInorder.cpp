#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode* node = root;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left; // Go to the leftmost node
        }
        else{
            if(st.empty() == true) break; // If stack is empty, we are done
            node = st.top(); // Get the top node
            st.pop();
            ans.push_back(node->data); // Visit the node
            node = node->right; // Now go to the right subtree
        }
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    vector<int> result = inorderTraversal(root);
    cout << "Preorder Traversal: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}
