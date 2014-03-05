#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//wrong
//int maxPathSum(TreeNode *root) {
    //if (root == NULL) {
        //return 0;
    //}
    //int maxsum;
    //int tmp;
    //maxsum = maxPathSum(root->left);
    //tmp = maxPathSum(root->right);
    //if (tmp > maxsum) {
        //maxsum = tmp;
    //}
    //return (root->val + maxsum);
//}

//int main() {
    //TreeNode a(1);
    //TreeNode b(2);
    //TreeNode c(3);
    //a.left = &b;
    //a.right = &c;
    //cout<< maxPathSum(&a);
    
//}
