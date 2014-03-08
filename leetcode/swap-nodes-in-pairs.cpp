#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *swapPairs(ListNode *head){
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *result;
    ListNode *tmpnode;
    ListNode *p1;
    ListNode *p2;

    p1 = head;
    p2 = p1->next;
    p1->next = p2->next;
    p2->next = p1;
    result = p2;
    tmpnode = p1;
    p1 = p1->next;
    while(p1 && p1->next){
        p2 = p1->next;
        p1->next = p2->next;
        p2->next = p1;
        tmpnode->next = p2;
        tmpnode = p1;
        p1 = p1->next;
    }

    return result;
}
int main(){
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
//    ListNode d(4);
    a.next=&b;
    b.next=&c;
//    c.next=&d;
    ListNode *tmp = swapPairs(&a);
    while(tmp){
        cout<<tmp->val;
        tmp=tmp->next;
    }
    return 0;
}
