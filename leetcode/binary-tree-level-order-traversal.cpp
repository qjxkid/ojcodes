#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//vector<vector<int> > levelOrder(TreeNode *root){
//    deque<TreeNode *> nodeq1;
//    deque<TreeNode *> nodeq2;
//    vector<vector<int> > result;
//    vector<int > tmpvec;
//    TreeNode *tmpnode;
//    if (root == NULL)
//        return result;
//    nodeq1.push_front(root);
//    while(!nodeq1.empty()){
//        tmpvec.clear();
//        while(!nodeq1.empty()){
//            tmpnode = nodeq1.back();
//            nodeq1.pop_back();
//            tmpvec.push_back(tmpnode->val);
//            if(tmpnode->left)
//                nodeq2.push_front(tmpnode->left);
//            if(tmpnode->right)
//                nodeq2.push_front(tmpnode->right);
//        }
//        result.push_back(tmpvec);
//        //only deque support swap func.
//        nodeq1.swap(nodeq2);
//    }
//    return result;
//}

vector<vector<int> > levelOrder(TreeNode *root){
    queue<TreeNode *> * nodeq1;
    queue<TreeNode *> * nodeq2;
    queue<TreeNode *> * tmpq;
    vector<vector<int> > result;
    vector<int > tmpvec;
    TreeNode *tmpnode;
    if (root == NULL)
        return result;
    nodeq1->push(root);
    while(!nodeq1->empty()){
        tmpvec.clear();
        while(!nodeq1->empty()){
            tmpnode = nodeq1->front();
            nodeq1->pop();
            tmpvec.push_back(tmpnode->val);
            if(tmpnode->left)
                nodeq2->push(tmpnode->left);
            if(tmpnode->right)
                nodeq2->push(tmpnode->right);
        }
        result.push_back(tmpvec);
        //only deque support swap func.
        tmpq = nodeq1;
        nodeq1 = nodeq2;
        nodeq2 = tmpq;
    }
    return result;
}


int main(){
    TreeNode a(3);
    TreeNode b(9);
    TreeNode c(20);
    TreeNode d(15);
    TreeNode e(7);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    vector<vector<int> > result = levelOrder(&a);
    int len1,len2;
    int i,j;
    len1 = result.size();
    for(i=0; i<len1; i++){
        len2 = result[i].size();
        for(j=0; j<len2; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
