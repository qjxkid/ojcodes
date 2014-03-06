#include <iostream>

using namespace std;

bool canJump(int A[], int n) {
    if (n == 0 || n == 1) {
        return true;
    }
    int i=0;
    while(i<n && A[i] != 0) {
        if (i== n-1) {
            return true;
        }
        i += A[i];
    }
    if (i== n-1) {
        return true;
    }
    return false;
}

int main(){
    int A[5] = {3,2,1,0,4};
    int B[5] = {2,3,1,1,4};
    cout<<canJump(A,5);
    cout<<canJump(B,5);
    return 0;
}
