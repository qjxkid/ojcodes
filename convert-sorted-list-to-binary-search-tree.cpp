#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *sortedListToBST(ListNode *head) {
    if (!head) {
        return NULL;
    }
    if (head->next == NULL) {
        TreeNode * result = new TreeNode(head->val);
        return result;
    }
    if (head->next->next == NULL) {
        TreeNode * left = new TreeNode(head->val);
        head = head->next;
        TreeNode * result = new TreeNode(head->val);
        result->left = left;
        return result;
    }
    ListNode tmphead(0);
    tmphead.next = head;
    ListNode *tmpnode;
    ListNode *tmpfastnode;
    ListNode *tmpprenode;
    tmpnode = head;
    tmpfastnode = head;
    tmpprenode = &tmphead;
    while (tmpfastnode) {
        tmpfastnode = tmpfastnode->next;
        if (!tmpfastnode) {
            break;
        }
        tmpnode = tmpnode->next;
        tmpprenode = tmpprenode->next;
        tmpfastnode = tmpfastnode->next;
    }
    TreeNode * result = new TreeNode(tmpnode->val);
    tmpprenode->next = NULL;
    TreeNode * left = sortedListToBST(head);
    TreeNode * right = sortedListToBST(tmpnode->next);
    result->left = left;
    result->right = right;
    return result;
}

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    TreeNode * tmp = sortedListToBST(&a);
    cout<<tmp->val<<endl;
    cout<<tmp->left->val<<endl;
    cout<<tmp->left->left->val<<endl;
    cout<<tmp->right->val<<endl;
    cout<<tmp->right->left->val<<endl;
    return 0;
}
