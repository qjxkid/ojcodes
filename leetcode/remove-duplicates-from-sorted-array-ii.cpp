#include <iostream>

using namespace std;
int removeDuplicates(int A[], int n) {
    int gap=0;
    int tmpnum = A[0];
    int cap=2;
    for(int i=1; i<n; i++){
        if (tmpnum == A[i]){
            cap--;
            if(cap > 0){
                A[i-gap] = A[i];
            }
            else {
                gap++;
            }
        }
        else{
            A[i-gap] = A[i];
            tmpnum = A[i];
            cap = 2;
        }
    }
    return n-gap;        
}

int main() {
    int A[] = {1,1,1,1};
    cout<<removeDuplicates(A,4);
}
