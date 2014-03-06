#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (head == NULL) {
        return head;
    }
    int i = 1;
    ListNode *tmpptr = head;
    ListNode *preptr = tmpptr;
    ListNode *newhead;
    ListNode *newend;
    if (m > 1) {
        i++;
        tmpptr = tmpptr->next;
    }
    stack<ListNode *> node_s;
    while(tmpptr) {
        if( i < m ) {
            tmpptr = tmpptr->next;
            preptr = preptr->next;
        }
        else if( i <= n ) {
            node_s.push(tmpptr);
            tmpptr = tmpptr->next;
        }
        else {
            break;
        }
        i++;
    }
    newend = tmpptr;
    if (!node_s.empty()) {
        newhead = node_s.top();
        tmpptr = newhead;
        node_s.pop();
    }
    while (!node_s.empty()) {
        tmpptr->next = node_s.top();
        tmpptr = tmpptr->next;
        node_s.pop();
    }
    tmpptr->next = newend;
    if (m == 1) {
        return newhead;
    }
    preptr->next = newhead;
    return head;
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

    ListNode *tmp = reverseBetween(&a,2,5);
    while(tmp) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }
}
