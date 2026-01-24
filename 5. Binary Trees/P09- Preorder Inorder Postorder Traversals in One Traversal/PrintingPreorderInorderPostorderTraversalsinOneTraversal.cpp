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

tuple<vector<int>, vector<int>, vector<int>> preInPostTraversal(TreeNode *root)
{
    vector<int> pre, in, post;
    if(root == NULL)
        return make_tuple(pre, in, post);
    stack<pair<TreeNode*, int>> st; // Pair of node and state
    st.push({root, 1}); // Start with root and state 1 (preorder)

    while(!st.empty()){
        auto it = st.top();
        st.pop();
        // Preorder state
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left != NULL){
                st.push({it.first->left, 1}); // Push left child with state 1
            }
        }
        // Inorder state
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right != NULL){
                st.push({it.first->right, 1}); // Push right child with state 1
            }
        }
        // Postorder state
        else{
            post.push_back(it.first->data);
        }
    }
    return make_tuple(pre, in, post);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> pre, in, post;
    tie(pre, in, post) = preInPostTraversal(root);

    cout << "Preorder: ";
    for (int val : pre)
        cout << val << " ";
    cout << "\nInorder: ";
    for (int val : in)
        cout << val << " ";
    cout << "\nPostorder: ";
    for (int val : post)
        cout << val << " ";
    cout << endl;
}
