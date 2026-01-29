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

bool areIdentical(TreeNode *root1, TreeNode *root2) {
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

int main() {
    // Example usage
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    TreeNode *root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(4);

    if(areIdentical(root1, root2))
        cout << "Trees are identical" << endl;
    else
        cout << "Trees are not identical" << endl;
    
    if(areIdentical(root1, root3))
        cout << "Trees are identical" << endl;
    else
        cout << "Trees are not identical" << endl;
}
