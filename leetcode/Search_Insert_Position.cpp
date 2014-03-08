#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int searchInsert(int A[], int n, int target) {
    if (n == 0)
        return 0;
    int bottom = 0;
    int top = n-1;
    int mid = (top + bottom)/2;
    while(top > bottom){
        if (target == A[mid]){
            return mid;
        }
        if (target < A[mid]){
            top = mid - 1;
        }
        if (target > A[mid]){
            bottom = mid + 1;
        }
        mid = (top + bottom)/2;
    }
    if (target == A[mid]){
        return mid;
    }
    if (target < A[mid]){
        return mid;
    }
    else{
        return mid+1;
    }
}

int main(){
    int A[4]={1,3,5,6};
    int B[1]={1};
    cout<<searchInsert(B,1,1)<<endl;
    cout<<searchInsert(A,4,5)<<endl;
    cout<<searchInsert(A,4,2)<<endl;
    cout<<searchInsert(A,4,7)<<endl;
    cout<<searchInsert(A,4,0)<<endl;
}
