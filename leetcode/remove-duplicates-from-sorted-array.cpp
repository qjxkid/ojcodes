#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(int A[], int n) {
    int gap=0;
    int tmpnum = A[0];
    for(int i=1; i<n; i++){
        if (tmpnum == A[i])
            gap++;
        else{
            A[i-gap] = A[i];
            tmpnum = A[i];
        }
    }
    return n-gap;
}
int main(){
    int A[5]={1,1,2,3,3};
    int n = removeDuplicates(A,5);
    for(int i=0; i<n; i++){
        cout<<A[i];
    }
    return 0;
}
