#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseKGroup(ListNode *head, int k) {
    stack<ListNode*> tmp;
    if (head == NULL || k == 1) {
        return head;
    }
    int i;
    ListNode * tmpnode = head;
    ListNode * tmpnode2;
    ListNode * newhead;
    for (i = 0; tmpnode && i < k; i++) {
        tmp.push(tmpnode);
        tmpnode = tmpnode->next;
    }
    if (i == k) {
        newhead = tmp.top();
        tmp.pop();
        tmpnode2 = newhead;
    }
    else {
        return head;
    }
    for (i = 1; i < k; i++) {
        tmpnode2->next = tmp.top();
        tmp.pop();
        tmpnode2 = tmpnode2->next;
    }
    while(tmpnode) {
        for (i = 0; tmpnode && i < k; i++) {
            tmp.push(tmpnode);
            tmpnode = tmpnode->next;
        }
        if (i == k) {
            for (i = 0; i < k; i++) {
                tmpnode2->next = tmp.top();
                tmp.pop();
                tmpnode2 = tmpnode2->next;
            }
        }
        else {
            while (!tmp.empty()) {
                tmpnode2->next = tmp.top();
                tmp.pop();
            }
        }
    }
    if (i==k) {
        tmpnode2->next = NULL;
    }
    return newhead;
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
    ListNode *tmp = reverseKGroup(&a, 5);
    while(tmp) {
        cout<<tmp->val;
        tmp = tmp->next;
    }
}
