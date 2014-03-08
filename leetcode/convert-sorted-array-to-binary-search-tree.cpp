#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *getTree(vector<int> &num, int bottom, int top){
    int mid = (top+bottom)/2;
    if (top<bottom) return NULL;
    if (top==bottom) return new TreeNode(num[mid]);
    TreeNode * result = new TreeNode(num[mid]);
    result->left = getTree(num, bottom, mid-1);
    result->right = getTree(num, mid+1, top);
    return result;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
    TreeNode * result = getTree(num, 0, num.size()-1);
    return result;
}

int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);
    num.push_back(7);
    TreeNode * result = sortedArrayToBST(num);
    TreeNode * tmp;
    tmp = result;
    while(tmp){
        cout<<tmp->val<<endl;
        tmp=tmp->right;
    }
    cout<<"/////////////////"<<endl;
    queue<TreeNode *> s;
    s.push(result);
    while(!s.empty()){
        tmp = s.front();
        s.pop();
        cout<<tmp->val<<endl;
        if(tmp->left)
            s.push(tmp->left);
        if(tmp->right)
            s.push(tmp->right);
    }
    return 0;
}
