#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getTreeDepthAndCheckBalence(TreeNode *root){
    if (root == NULL) return 0;
    int leftdepth = getTreeDepthAndCheckBalence(root->left);
    int rightdepth = getTreeDepthAndCheckBalence(root->right);
    if (rightdepth == -1 || leftdepth == -1)
        return -1;
    int maxdepth = leftdepth;
    if (abs(leftdepth - rightdepth) < 2){
        if (rightdepth > maxdepth)
            maxdepth = rightdepth;
        return 1+maxdepth;
    }
    return -1;
}

bool isBalanced(TreeNode *root) {
    if (root == NULL) return true;
    int leftdepth = getTreeDepthAndCheckBalence(root->left);
    int rightdepth = getTreeDepthAndCheckBalence(root->right);
    if (leftdepth == -1 || rightdepth == -1)
        return false;
    if (abs(leftdepth - rightdepth) < 2){
        return true;
    }
    return false;
}

int main(){
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    d.left = &e;
    if (isBalanced(&a))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
