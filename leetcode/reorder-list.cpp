#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode *head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) return;
    stack<ListNode *> nodestack;
    ListNode *tmp = head;
    while(tmp) {
        nodestack.push(tmp);
        tmp = tmp->next;
    }
    ListNode *forward, *backward;
    forward = head;
    backward = nodestack.top();
    nodestack.pop();
    while(forward->next != backward && forward != backward) {
        backward->next = forward->next;
        forward->next = backward;
        forward = backward->next;
        backward = nodestack.top();
        nodestack.pop();
    }
    if (forward == backward) {
        forward->next = NULL;
    }
    else {
        backward->next = NULL;
    }
}

int main() {
    ListNode a[] = {
        ListNode(1),
        ListNode(2),
        //ListNode(3),
        //ListNode(4),
        //ListNode(5),
        //ListNode(6),
        };
    int len = sizeof(a)/sizeof(ListNode);
    int i;
    for (i = 0; i < len - 1; i++) {
        a[i].next = &a[i+1];
    }
    reorderList(&a[0]);
    ListNode *tmp = &a[0];
    while(tmp) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }
    return 0;
}
