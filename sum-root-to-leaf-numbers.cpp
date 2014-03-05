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

stack<int> num_s;
vector<int> sums_v;

void getSum(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    num_s.push(root->val);
    if (root->left == NULL && root->right == NULL) {
        //get result
        stack<int> tmp_s;
        int sum = 0;
        int tmp2;
        while(!num_s.empty()) {
            tmp_s.push(num_s.top());
            num_s.pop();
        }
        while (!tmp_s.empty()) {
            sum *= 10;
            tmp2 = tmp_s.top();
            sum += tmp2;
            num_s.push(tmp2);
            tmp_s.pop();
        }
        sums_v.push_back(sum);
        num_s.pop();
        return;
    }
    getSum(root->left);
    getSum(root->right);
    num_s.pop();
}

int sumNumbers(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->val;
    }
    num_s.push(root->val);
    getSum(root->left);
    getSum(root->right);
    int ans = 0;
    int len = sums_v.size();
    int i;
    for (i = 0; i < len; i++) {
        ans += sums_v[i];
    }

    return ans;
}

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.left = &b;
    a.right = &c;
    cout<<sumNumbers(&a)<<endl;
    //TreeNode a(1);
    //TreeNode a(1);
    //TreeNode a(1);
    //TreeNode a(1);
}
