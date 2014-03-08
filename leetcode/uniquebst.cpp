#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        static int tree[0xfffff] = {1,1,2,5};
        static int top = 3;
        if(n > top){
            tree[n] = 0;
            for(int i = 0; i < n/2; i++){
                tree[n] += numTrees(i)*numTrees(n-i-1)*2;
            }
            if(n%2) tree[n] += numTrees(n/2)*numTrees(n/2);
            top = n;
        }
        return tree[n];
    }
};
int main(){
    int a;
    cin>>a;
    Solution s;
    while(a!=0){
        cout<<s.numTrees(a)<<endl;
        cin>>a;
    }
    return 0;
}
