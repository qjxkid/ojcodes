#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int maxSubArray(int A[], int n){
    if (n==0) return 0;
    int tmpmax = A[0];
    int totalmax = tmpmax;
    for(int i=1; i<n; i++){
        if (tmpmax > 0)
            tmpmax += A[i];
        else
            tmpmax = A[i];
        totalmax = totalmax > tmpmax ? totalmax : tmpmax;
    }
    return totalmax;
}
int main(){
    int A[9] = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(A,9)<<endl;
    return 0;
}
