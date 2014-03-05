#include <iostream>
#include "TreeNode.h"
using namespace std;

int minDepth(TreeNode *root) {
    if (!root->left && !root->right) {
        return 1;
    }
    if (root->left && root->right) {
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
    if (root->left) {
        return 1 + minDepth(root->left);
    }
    if (root->right) {
        return 1 + minDepth(root->right);
    }
}

int main() {
    TreeNode a(1);
    TreeNode b(1);
    //TreeNode c(1);
    //TreeNode d(1);
    //TreeNode e(1);
    a.left = &b;
    //a.right = &c;
    //c.left = &d;
    //c.right = &e;
    cout<<minDepth(&a)<<endl;
    return 0;
}
