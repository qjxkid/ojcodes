#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *sortList(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *pivot = head;
    ListNode *pivotend = pivot;
    head = head->next;
    ListNode *llist = NULL, *rlist = NULL;
    ListNode *ltmp = NULL, *rtmp = NULL;

    while(head) {
        if (head->val == pivot->val) {
            pivotend->next = head;
            head = head->next;
            pivotend = pivotend->next;
            pivotend->next = NULL;
        }
        else if (head->val > pivot->val) {
            if (rtmp == NULL) {
                rtmp = head;
                rlist = rtmp;
            }
            else {
                rtmp->next = head;
                rtmp = rtmp->next;
            }
            head = head->next;
            rtmp->next = NULL;
        }
        else {
            if (ltmp == NULL) {
                ltmp = head;
                llist = ltmp;
            }
            else {
                ltmp->next = head;
                ltmp = ltmp->next;
            }
            head = head->next;
            ltmp->next = NULL;
        }
    }
    llist = sortList(llist);
    rlist = sortList(rlist);
    pivotend->next = rlist;
    if (!llist) {
        return pivot;
    }
    ltmp = llist;
    while(ltmp->next) {
        ltmp = ltmp->next; 
    }
    ltmp->next = pivot;
    return llist;
}

int main() {
    ListNode a(1);
    ListNode b(1);
    ListNode c(3);
    ListNode d(1);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    ListNode *tmp = sortList(&a);
    while(tmp) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }
    return 0;
}
