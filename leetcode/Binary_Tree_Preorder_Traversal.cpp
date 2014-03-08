#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode*> nodestack;
    TreeNode * tmpnode;
    if (root == NULL)
        return result;
    nodestack.push(root);
    while(!nodestack.empty()){
        tmpnode = nodestack.top();
        nodestack.pop();
        result.push_back(tmpnode->val);
        if (tmpnode->right != NULL)
            nodestack.push(tmpnode->right);
        if (tmpnode->left != NULL)
            nodestack.push(tmpnode->left);
    }
    return result;
}

int main(){
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.right = &b;
    b.left = &c;
    vector<int> d = preorderTraversal(&a);
    for(int i=0; i<d.size(); i++)
        cout<<d[i]<<endl;
}
