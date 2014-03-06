#include <iostream>
#include <queue>
using namespace std;
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
    queue<TreeLinkNode *> node1_q;
    queue<TreeLinkNode *> node2_q;
    TreeLinkNode *tmpnode;
    TreeLinkNode *prenode = NULL;
    if (root == NULL) {
        return;
    }
    node1_q.push(root);
    while (!node1_q.empty()) {
        while (!node1_q.empty()) {
            if (prenode == NULL) {
                prenode = node1_q.front();
            }
            else {
                prenode->next = node1_q.front();
                prenode = prenode->next;
            }
            node1_q.pop();
            if (prenode->left) {
                node2_q.push(prenode->left);
            }
            if (prenode->right) {
                node2_q.push(prenode->right);
            }
        }
        prenode = NULL;
        swap(node1_q, node2_q);
    }
}

int main() {
    TreeLinkNode a(1);
    TreeLinkNode b(2);
    TreeLinkNode c(3);
    TreeLinkNode d(4);
    TreeLinkNode e(5);
    TreeLinkNode f(7);
    a.left = &b;
    b.left = &d;
    b.right = &e;
    a.right = &c;
    c.right = &f;

    connect(&a);
    TreeLinkNode *tmp;
    tmp = &b;
    while(tmp) {
        cout<<tmp->val<< " ";
        tmp = tmp->next;
    }
    cout<<"\n";
    tmp = &d;
    while(tmp) {
        cout<<tmp->val<< " ";
        tmp = tmp->next;
    }
}
