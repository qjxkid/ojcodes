#include <iostream>
#include "TreeNode.h"

using namespace std;

TreeNode * flatTree(TreeNode *root) {
    //root shouldn't be a NULL
    TreeNode * tmpleft = root->left;
    TreeNode * tmpright = root->right;
    TreeNode * tmp;
    if (tmpleft) {
        root->left = NULL;
        root->right = tmpleft;
        tmp = flatTree(tmpleft);
        tmp->right = tmpright;
    }
    if (tmpright) {
        flatTree(tmpright);
    }
    tmp = root;
    while (tmp->right) {
        tmp = tmp->right;
    }
    return tmp;
}

void flatten(TreeNode *root) {
    if (!root) {
        return;
    }
    flatTree(root);
}

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    a.left = &b;
    b.left = &c;
    b.right = &d;
    a.right = &e;
    e.right = &f;
    TreeNode *tmp = &a;
    flatten(tmp);
    while (tmp) {
        cout<<tmp->val<<endl;
        tmp = tmp->right;
    }
    return 0;
}
