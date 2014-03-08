#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL)
        return head;
    int tmp = head->val;
    ListNode *tmpnode;
    ListNode *currentnode = head;
    while(currentnode->next != NULL){
        tmpnode = currentnode->next;
        if(tmp == tmpnode->val){
            currentnode->next = tmpnode->next;
            tmpnode->next = NULL;
            //delete tmpnode;
        }
        else{
            tmp = tmpnode->val;
            currentnode = tmpnode;
        }
    }
    return head;
}
int main(){
    ListNode a(1);
    ListNode b(1);
    ListNode c(2);
    a.next = &b;
    b.next = &c;
    deleteDuplicates(&a);
    return 0;
}
