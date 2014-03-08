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
    tmpnode = root;
    nodestack.push(root);
    while(!nodestack.empty()){
        if (tmpnode != NULL){
            tmpnode = tmpnode->left;
            while(tmpnode != NULL){
                nodestack.push(tmpnode);
                tmpnode = tmpnode->left;
            }
        }
        tmpnode = nodestack.top();
        nodestack.pop();
        result.push_back(tmpnode->val);
        if(tmpnode->right != NULL){
            tmpnode = tmpnode->right;
            nodestack.push(tmpnode);
        }
        else
            tmpnode = NULL;
    }
    return result;
}

int main(){
    TreeNode a(2);
    TreeNode b(3);
    TreeNode c(1);
    a.left = &b;
    b.left = &c;
    vector<int> d = preorderTraversal(&a);
    for(int i=0; i<d.size(); i++)
        cout<<d[i]<<endl;
}
