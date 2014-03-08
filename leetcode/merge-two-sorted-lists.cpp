#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *currnode;
    ListNode * result;
    if (!(l1 && l2)){
        if(l1 == NULL)
            return l2;
        else
            return l1;
    }
    if(l1->val < l2->val){
        currnode = l1;
        l1 = l1->next;
    }
    else{
        currnode = l2;
        l2 = l2->next;
    }
    result = currnode;
    while(l1 && l2){
        if(l1->val < l2->val){
            currnode->next = l1;
            l1 = l1->next;
        }
        else{
            currnode->next = l2;
            l2 = l2->next;
        }
        currnode = currnode->next;
    }
    if(l1 != NULL){
        currnode->next = l1;
    }
    if(l2 != NULL){
        currnode->next = l2;
    }
    return result;
}
int main(){
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    a->next = c;
    b->next = d;
    ListNode *e = mergeTwoLists(a,b);
    while(e != NULL){
        cout<<e->val<<endl;
        e = e->next;
    }
    return 0;
}
