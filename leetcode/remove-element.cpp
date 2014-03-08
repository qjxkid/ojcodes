#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int removeElement(int A[], int n, int elem) {
    int gap=0;
    for(int i=0; i<n; i++){
        if (A[i] == elem)
            gap++;
        else
            A[i-gap] = A[i];
    }
    return n-gap;
}

int main(){
//    int A[5] = {1,1,2,3,4};
//    removeElement(A,5,1);
//    for(int i=0;i<5;i++)
//        cout<<A[i]<<endl;
    int A[1] = {2};
    removeElement(A,1,3);
    for(int i=0;i<1;i++)
        cout<<A[i]<<endl;
}
