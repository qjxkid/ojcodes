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
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    if (!root) {
        return result;
    }
    stack<TreeNode *> s1,s2;
    TreeNode * tmp;
    s1.push(root);
    while (!s1.empty()) {
        tmp = s1.top();
        s1.pop();
        s2.push(tmp);
        if (tmp->left) {
            s1.push(tmp->left);
        }
        if (tmp->right) {
            s1.push(tmp->right);
        }
    }
    while (!s2.empty()) {
        result.push_back(s2.top()->val);
        s2.pop();
    }
    return result;
}
int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.right = &b;
    b.left = &c;
    vector<int> result = postorderTraversal(&a);
    int len = result.size();
    int i;
    for (i = 0; i < len; i++) {
        cout<<result[i]<<endl;
    }
    return 0;
}
