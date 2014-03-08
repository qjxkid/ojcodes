#include <cstdio>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int main(){
    TreeNode *p,*q;
    q=NULL;
    p=NULL;
    if( !(p&&q) ){
        cout << (p==q) <<endl;
        cout << (q==NULL) <<endl;
        cout << (p==q==NULL) <<endl;
        cout << (3==3==1) <<endl;
        cout << (1==2==2) <<endl;
        if (p == q == NULL)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
