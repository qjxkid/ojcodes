#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> treeToVector(TreeNode * root){
    vector<int> result;
    if (root == NULL) {
        return result;
    }
    TreeNode * tmpnode;
    queue<TreeNode *> preq,currq;
    preq.push(root);
    result.push_back(root->val);
    while(!preq.empty()){
        while(!preq.empty()){
            tmpnode = preq.front();
            preq.pop();
            if(tmpnode->left){
                currq.push(tmpnode->left);
                result.push_back(tmpnode->left->val);
            }
            else {
                result.push_back(-1);
            }
            if(tmpnode->right){
                currq.push(tmpnode->right);
                result.push_back(tmpnode->right->val);
            }
            else {
                result.push_back(-1);
            }
        }
        swap(preq,currq);
    }
    return result;
}

int isVecSym(vector<int> &leftvec, vector<int> &rightvec, int bottom, int len){
    int i;
    int node=0;
    for (i = 0; i < len; i++) {
        if (leftvec[bottom+i] != -1) {
            node++;
        }
        if (leftvec[bottom+i] != rightvec[bottom+len-1-i]) {
            return -1;
        }
    }
    return node;
    
}

bool isSymmetric(TreeNode *root) {
    if (root == NULL) {
        return true;
    }
    vector<int> leftvec = treeToVector(root->left);
    vector<int> rightvec = treeToVector(root->right);

    if (leftvec.size() != rightvec.size() ) {
        return false;
    }
    if (leftvec.size() == 0) {
        return true;
    }
    int len = leftvec.size();
    int i = 0;
    int j = 1;
    int m = 1;
    int k;
    while( i < len ){
        j = isVecSym(leftvec, rightvec, i, m);
        if ( j == -1 ){
            return false;
        }
        if (j == 0) break;
        i += m;
        m = j<<1;
    }
    return true;
}

int main(){
    //TreeNode a(1);
    //TreeNode b(2);
    //TreeNode c(2);
    //TreeNode d(3);
    //TreeNode e(4);
    //TreeNode f(3);
    //TreeNode g(4);
    //a.left = &b;
    //a.right = &c;
    //b.left = &d;
    //b.right = &e;
    //c.left = &g;
    //c.right = &f;

    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(2);
    TreeNode d(3);
    TreeNode e(3);
    a.left = &b;
    a.right = &c;
    b.right = &d;
    c.left = &e;
    if(isSymmetric(&a)) cout<<"yes!"<<endl;
    else cout<<"no!"<<endl;
    //vector<int> test = treeToVector(&a);
    //int len = test.size();
    //int i;
    //for (i = 0; i < len; i++) {
        //cout<<test[i]<<endl;
    //}
    return 0;
}
