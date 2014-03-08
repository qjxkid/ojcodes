#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getCycleBegin(ListNode* head, ListNode* meet){
	while(head != meet){
		head=head->next;
		meet=meet->next;
	}
	return head;
}

ListNode *detectCycle(ListNode *head) {
    if (head == NULL)
        return NULL;
    ListNode *slowptr, *fastptr;
    slowptr = head->next;
    if(slowptr == NULL)
        return NULL;
    fastptr = head->next->next;
    while(slowptr!=NULL && fastptr!=NULL){
        if(slowptr == fastptr){
            return getCycleBegin(head,slowptr);
        }
        slowptr = slowptr->next;
        fastptr = fastptr->next;
        if (fastptr==NULL)
            return NULL;
        fastptr = fastptr->next;
    }
    return NULL;
}

int main(){
    return 0;
}


