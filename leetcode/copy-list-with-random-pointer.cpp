#include <iostream>
#include <unordered_map>
using namespace std;

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
RandomListNode *copyRandomList(RandomListNode *head) {
    unordered_map<int, RandomListNode* > nodetable;
    RandomListNode *optr = head;
    RandomListNode *result, *tmpptr;
    if (optr == NULL) {
        return optr;
    }
    result = new RandomListNode(optr->label);
    nodetable[optr->label] = result;
    optr = optr->next;
    tmpptr = result;
    //copy label and nextptr
    while (optr) {
        tmpptr->next = new RandomListNode(optr->label);
        tmpptr = tmpptr->next;
        nodetable[tmpptr->label] = tmpptr;
        optr = optr->next;
    }
    
    //copy randomptr
    optr = head;
    tmpptr = result;
    while (optr) {
        if (optr->random != NULL) {
            tmpptr->random = nodetable[optr->random->label];
        }
        tmpptr = tmpptr->next;
        optr = optr->next;
    }
    return result;
}

int main() {
   return 0; 
}
