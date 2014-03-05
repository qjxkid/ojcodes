#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool hasPathSum(TreeNode *root, int sum) {
    if (!root) {
        return false;
    }
    int value = sum - root->val;
    if (!(root->left) && !(root->right) && value == 0) {
        return true;
    }
    if (hasPathSum(root->left, value)) {
        return true;
    }
    if (hasPathSum(root->right, value)) {
        return true;
    }
    return false;
}
int main() {
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode i(1);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    d.left = &g;
    d.right = &h;
    c.left = &e;
    c.right = &f;
    f.right = &i;
    if(hasPathSum(&a, 22)) {
        cout<<"yes"<<endl;
    }
    else
        cout<<"no"<<endl;
    return 0;
}
