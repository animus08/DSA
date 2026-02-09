# include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution{
    public:
        bool isSymmetric(TreeNode* root){
            if(root == NULL) return true;

            queue<TreeNode*> q;
            q.push(root);
            q.push(root);

            while(!q.empty()){
                TreeNode* t1 = q.front(); q.pop();
                TreeNode* t2 = q.front(); q.pop();

                if(t1 == NULL && t2 == NULL) continue;
                if(t1 == NULL || t2 == NULL) return false;
                if(t1->val != t2->val) return false;

                q.push(t1->left);
                q.push(t2->right);

                q.push(t1->right);
                q.push(t2->left);
            }
            return true;
        }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    cout << sol.isSymmetric(root) << endl;

    return 0;
}
