#include <iostream>
#include "TreeNode.h"
#include <stack>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    queue<TreeNode *> nodeq1;
    queue<TreeNode *> nodeq2;
    stack<int > tmp_s;
    vector<vector<int> > result;
    vector<int > tmpvec;
    TreeNode *tmpnode;
    int i = 0;
    if (root == NULL)
        return result;
    nodeq1.push(root);
    while(!nodeq1.empty()){
        tmpvec.clear();
        if (i%2 == 0) {
            while(!nodeq1.empty()){
                tmpnode = nodeq1.front();
                nodeq1.pop();
                tmpvec.push_back(tmpnode->val);
                if(tmpnode->left)
                    nodeq2.push(tmpnode->left);
                if(tmpnode->right)
                    nodeq2.push(tmpnode->right);
            }
        }
        else {
            while(!nodeq1.empty()){
                tmpnode = nodeq1.front();
                nodeq1.pop();
                tmp_s.push(tmpnode->val);
                if(tmpnode->left)
                    nodeq2.push(tmpnode->left);
                if(tmpnode->right)
                    nodeq2.push(tmpnode->right);
            }
            while (!tmp_s.empty()) {
                tmpvec.push_back(tmp_s.top());
                tmp_s.pop();
            }
        }
        result.push_back(tmpvec);
        swap(nodeq1, nodeq2);
        i++;
    }
    return result;
}

int main() {
    TreeNode a(3); 
    TreeNode b(9); 
    TreeNode c(20); 
    TreeNode d(15); 
    TreeNode e(7); 
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    vector<vector<int> > ans = zigzagLevelOrder(&a);
    int i,j;
    for (i = 0; i < ans.size(); i++) {
        for (j = 0; j < ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
