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

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<TreeNode *> st;
    TreeNode *current = root;
    TreeNode *temp = NULL;

    while (current != NULL || !st.empty())
    {
        if (current != NULL)
        {
            st.push(current);
            current = current->left; // Go to the leftmost node
        }
        else
        {
            temp = st.top()->right; // Get the top node
            if (temp == NULL)
            {
                temp = st.top(); // If right child is NULL, visit the node
                st.pop();
                ans.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data); // Visit the node
                }
            }
            else
            {
                current = temp; // If right child exists, go to it
            }
        }
    }
    return ans; // Return the postorder traversal result
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);
    root->right->left->right->right = new TreeNode(8);

    vector<int> result = postorderTraversal(root);
    cout << "Postorder Traversal: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}
