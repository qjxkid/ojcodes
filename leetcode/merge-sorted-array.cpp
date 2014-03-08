#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

void merge(int A[], int m, int B[], int n) {
    int C[100000];
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(A[i]<B[j]){
            C[k++]=A[i];
            i++;
        }
        else{
            C[k++]=B[j];
            j++;
        }
    }
    while(i<m){
        C[k++]=A[i];
        i++;
    }
    while(j<n){
        C[k++]=B[j];
        j++;
    }
    memcpy(A,C,sizeof(int)*k);
}

int main(){
    int A[20]={2,4};
    int B[]={1,3};
    merge(A,2,B,2);
    for(int i=0; i<4; i++)
        cout<<A[i];
    return 0;
}
