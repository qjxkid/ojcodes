#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

stack<int> result_s;
vector<vector<int> > result_v;
void getPathSum(TreeNode * root,  int sum){
    int value = sum - root->val;
    result_s.push(root->val);
    if (!(root->left) && !(root->right) && value == 0) {
        stack<int> tmp;
        vector<int> tmp_v;
        while(!result_s.empty()){
            tmp.push(result_s.top());
            result_s.pop();
        }
        while(!tmp.empty()) {
            tmp_v.push_back(tmp.top());
            result_s.push(tmp.top());
            tmp.pop();
        }
        result_v.push_back(tmp_v);
        //result_s.pop();
        //return;
    }
    if (root->left) {
        getPathSum(root->left, value);
    }
    if (root->right) {
        getPathSum(root->right, value);
    }
    result_s.pop();
}
vector<vector<int> > pathSum(TreeNode *root, int sum) {
    getPathSum(root, sum);
    return result_v;
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
    TreeNode u(1);
    TreeNode k(5);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    d.left = &g;
    d.right = &h;
    c.left = &e;
    c.right = &f;
    f.right = &u;
    f.left = &k;
    vector<vector<int> > tmp = pathSum(&a, 22);
    int len = tmp.size();
    int len2 = tmp[0].size();
    int i,j;
    for (i = 0; i < len; i++) {
        for (j = 0; j < len2; j++) {
            cout<<tmp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
