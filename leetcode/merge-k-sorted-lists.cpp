#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

////use merge sort
//ListNode *mergeLists(ListNode *l1, ListNode *l2) {
    //ListNode *result, *tmp, *cnt;
    //if (l1 == NULL) return l2;
    //if (l2 == NULL) return l1;
    //if (l1->val < l2->val) {
        //tmp = l1;
        //l1 = l1->next;
        //tmp->next = NULL;
        //result = tmp;
    //}
    //else {
        //tmp = l2;
        //l2 = l2->next;
        //tmp->next = NULL;
        //result = tmp;
    //}
    //cnt = result;
    //while(l1 && l2) {
        //if (l1->val < l2->val) {
            //tmp = l1;
            //l1 = l1->next;
            //tmp->next = NULL;
        //}
        //else {
            //tmp = l2;
            //l2 = l2->next;
            //tmp->next = NULL;
        //}
        //cnt->next = tmp;
        //cnt = cnt->next;
    //}
    //if (l1 == NULL) cnt->next = l2;
    //if (l2 == NULL) cnt->next = l1;
    //return result;
//}

//ListNode *mergeKLists(vector<ListNode *> &lists) {
    //if (lists.size() == 0) return NULL;
    //if (lists.size() == 1) return lists.at(0);
    //queue<ListNode *> cntq, nextq;
    //ListNode *tmpnode1, *tmpnode2;
    //ListNode *result;
    //int i;
    //int len = lists.size();
    //for (i = 0; i < len; i++) {
        //cntq.push(lists.at(i));
    //}
    //while(cntq.size() != 1) {
        //while(cntq.size() != 0) {
            //tmpnode1 = cntq.front();
            //cntq.pop();
            //if (cntq.size() >0) {
                //tmpnode2 = cntq.front();
                //cntq.pop();
                //nextq.push(mergeLists(tmpnode1, tmpnode2));
            //}
            //else {
                //nextq.push(tmpnode1);
            //}
        //}
        //swap(cntq, nextq);
    //}
    //result = cntq.front();
    //cntq.pop();
    //return result;
//}

//use minheap
int heaplength;
void incrasekey(ListNode **pos, int i, ListNode *x) {
    pos[i] = x;
    ListNode *tmp;
    int parent = (i-1)/2;
    while(i>=0 && pos[parent]->val > pos[i]->val){
        tmp = pos[i];
        pos[i] = pos[parent];
        pos[parent] = tmp;
        i = parent;
        parent = (i-1)/2;
    }
}

void heapify(ListNode **pos, int i) {
    int l=i*2+1;
    int r=i*2+2;
    int minest;
    ListNode *tmp;
    if (l < heaplength && pos[l]->val < pos[i]->val)
        minest = l;
    else
        minest = i;
    if (r < heaplength && pos[r]->val < pos[minest]->val)
        minest = r;
    if (minest != i){
        tmp = pos[i];
        pos[i] = pos[minest];
        pos[minest] = tmp;
        heapify(pos, minest);
    }
}

ListNode* top(ListNode **pos) {
    if (heaplength == 0) return NULL;
    return pos[0];
}

void push(ListNode **pos, ListNode *x) {
    if ( x == NULL) return;
    incrasekey(pos, heaplength, x);
    heaplength++;
}

void pop(ListNode **pos) {
    if (heaplength == 0) return;
    ListNode *tmp = pos[0];
    pos[0] = pos[0]->next;
    tmp->next = NULL;
    if (pos[0] == NULL){
        pos[0] = pos[heaplength-1];
        heaplength--;
    }
    heapify(pos, 0);
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) return NULL;
    if (lists.size() == 1) return lists.at(0);
    ListNode *tmpnode;
    ListNode *result = NULL;
    int i;
    int len = lists.size();
    ListNode **pos = (ListNode **)malloc(len * sizeof(ListNode *));
    heaplength = 0;
    for (i = 0; i < len; i++) {
        push(pos, lists.at(i));
    }
    result = top(pos);
    pop(pos);
    tmpnode = result;
    while(heaplength > 1) {
        tmpnode->next = top(pos);
        pop(pos);
        tmpnode = tmpnode->next;
    }
    if (heaplength == 1)
        tmpnode->next = top(pos);
    return result;
}

int main() {
    ListNode a(1);
    ListNode b(3);
    ListNode c(5);
    ListNode d(7);
    ListNode e(9);

    ListNode f(2);
    ListNode g(4);
    ListNode h(6);
    ListNode i(8);
    ListNode j(10);
    
    ListNode f1(12);
    ListNode g1(14);
    ListNode h1(16);
    ListNode i1(18);
    ListNode j1(110);

    vector<ListNode *>lists;
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    f.next = &g;
    g.next = &h;
    h.next = &i;
    i.next = &j;

    f1.next = &g1;
    g1.next = &h1;
    h1.next = &i1;
    i1.next = &j1;

    //lists.push_back(&a);
    //lists.push_back(&f1);
    //lists.push_back(&f);

    lists.push_back(NULL);
    lists.push_back(NULL);
    
    ListNode *tmp = mergeKLists(lists);

    while(tmp) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }

    cout<<"123"<<endl;
    return 0;
}
