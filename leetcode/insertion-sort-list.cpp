#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
    
ListNode *insertionSortList(ListNode *head) {
    ListNode *end = head, *cnt = head;
    ListNode *tmp;
    if (cnt == NULL) return NULL;
    while(end->next) {
        tmp = end->next;
        if (tmp->val > end->val) {
            end = end->next;
            continue;
        }
        end->next = tmp->next;
        cnt = head;
        if (tmp->val < cnt->val) {
            tmp->next = cnt;
            head = tmp;
            end = cnt;
        }
        else if (tmp->val > end->val) {
            tmp->next = end->next;
            end->next = tmp;
            end = end->next;
        }
        else {
            while(cnt != end && tmp->val > cnt->next->val) {
                cnt = cnt->next;
            }
            if (cnt == end) {
                tmp->next = end->next;
                end->next = tmp;
                end = end->next;
            }
            else {
                tmp->next = cnt->next;
                cnt->next = tmp;
            }
        }
    }
    return head;
}

int main(){
    ListNode a(4);
    ListNode b(3);
    ListNode c(2);
    ListNode d(1);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    ListNode *tmp = insertionSortList(&a);
    while(tmp) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }
    return 0;
}
