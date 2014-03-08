#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode():left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
//    if(root == NULL)
//        return;
//    connect(root->left);
//    cout<<root->val<<endl;
//    connect(root->right);
    TreeLinkNode *prelevel = root;
    TreeLinkNode *currentlevel = prelevel->left;
    TreeLinkNode *tmpnode;
    while(currentlevel != NULL){
        tmpnode = prelevel;
        while(tmpnode->next != NULL){
            tmpnode->left->next = tmpnode->right;
            tmpnode->right->next = tmpnode->next->left;
            tmpnode = tmpnode->next;
        }
        tmpnode->left->next = tmpnode->right;
        tmpnode->right->next = NULL;
        prelevel = currentlevel;
        currentlevel = prelevel->left;
    }
}
int main(){
    TreeLinkNode root[9];
    for(int i=1; i<9; i++){
        root[i].val = i;
        if(i<4){
            root[i].left = &(root[i*2]);
            root[i].right = &(root[i*2+1]);
        }
    }
    connect(&(root[1]));
    return 0;
}
