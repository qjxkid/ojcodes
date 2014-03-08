#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == NULL)
        return false;
    ListNode *slowptr, *fastptr;
    slowptr = head->next;
    if(slowptr == NULL)
        return false;
    fastptr = head->next->next;
    while(slowptr!=NULL && fastptr!=NULL){
        if(slowptr == fastptr){
            return true;
        }
        slowptr = slowptr->next;
        fastptr = fastptr->next;
        if (fastptr==NULL)
            return false;
        fastptr = fastptr->next;
    }
    return false;
}

int main(){
    ListNode a(1);
    a.next = &a;
    if (hasCycle(&a)) {
        cout<<"yes!"<<endl;
    }
    else
        cout<<"no!"<<endl;
    return 0;
}

