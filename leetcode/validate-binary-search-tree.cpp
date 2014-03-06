#include <iostream>
#include "TreeNode.h"

using namespace std;

bool getMinMaxValid(TreeNode *root, int &minv, int &maxv) {
    int leftmax, leftmin;
    int rightmax, rightmin;
    if (root->left) {
        if (root->left->val >= root->val) {
            return false;
        }
        if (!getMinMaxValid(root->left, leftmin, leftmax))
            return false;
        if (leftmax >= root->val)
            return false;
        minv = leftmin;
    }
    else minv = root->val;
    if (root->right) {
        if (root->right->val <= root->val) {
            return false;
        }
        if (!getMinMaxValid(root->right, rightmin, rightmax))
            return false;
        if (rightmin <= root->val)
            return false;
        maxv = rightmax;
    }
    else maxv = root->val;
    return true;
}

bool isValidBST(TreeNode *root) {
    if (!root)
        return true;
    int minv, maxv;
    bool valid;
    if (root->left) {
        if (!getMinMaxValid(root->left, minv, maxv))
            return false;
        if (maxv >= root->val) 
            return false;
    }
    if (root->right) {
        if (!getMinMaxValid(root->right, minv, maxv))
            return false;
        if (minv <= root->val)
            return false;
    }
    return true;
}

int main() {
    TreeNode a(10);
    TreeNode b(5);
    TreeNode c(15);
    TreeNode d(11);
    TreeNode e(20);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    if (isValidBST(&a)) {
        cout<<"yes"<<endl;
    }
    else cout<<"no"<<endl;
    return 0;
}
