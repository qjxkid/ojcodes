#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (n == 0) {
        return head;
    }
    int i = -1;
    ListNode * currnode;
    ListNode * prenode;
    prenode = currnode = head;
    while(currnode){
        if (i >= n) {
            prenode = prenode->next;
        }
        i++;
        currnode = currnode->next;
    }
    if (i < n) {
        head = head->next;
        prenode->next = NULL;
        delete prenode;
        prenode = NULL;
        return head;
    }
    currnode = prenode->next;
    prenode->next = currnode->next;
    currnode->next = NULL;
    delete currnode;
    currnode = NULL;
    return head;
}

int main(){
    int i=0;
    ListNode *test = new ListNode(1);
    ListNode *tmp = test;
    for(i=1; i<5; i++){
        tmp->next = new ListNode(i+1);
        tmp = tmp->next;
    }
    tmp = removeNthFromEnd(test, 2);
    while(tmp) {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    return 0;


}
