#include <iostream>
#include <cstring>
using namespace std;

int jump(int A[], int n) {
    if (n == 1) {
        return 0;
    }
    int *minjump = new int[n];
    int i=0, j=0;
    int cnt = A[0];
    int steps = 1;
    int jumplongest = cnt;
    int jumpnearest = 1;
    int lastnearest = 1;
    int lastlongest = cnt;
    while (jumplongest < n-1) {
        while (A[i] == 0) {
            i++;
        }
        cnt = A[i];
        j = 1;
        jumpnearest = i+j+A[i+j];
        jumplongest = i+j+A[i+j];
        for (; i+j <= lastlongest; j++) {
            if (jumpnearest > i+j+A[i+j]) {
                jumpnearest = i+j+A[i+j];
            }
            if (jumplongest < i+j+A[i+j]) {
                jumplongest = i+j+A[i+j];
            }
        }
        i = lastnearest;
        lastnearest = jumpnearest > lastlongest + 1 ? jumpnearest : lastlongest + 1;
        if (jumplongest <= lastlongest) {
            continue;
        }
        lastlongest = jumplongest;
        steps++;
    }
    return steps;
    //int MAX = 0x7fffffff;
    //memset(minjump, 0, sizeof(int)*n);
    //for (i = 1; i < n; i++) {
        //minjump[i] = MAX;
    //}
    //minjump[0] = 0;
    //for (i = 0; i < n-1; i++) {
        //j = A[i];
        //if (i+j >= n) {
            //j = n-1;
            //if (minjump[i+j] > minjump[i]+1) {
                //return minjump[i]+1;
            //}
        //}
        //for (; j > 0; j--) {
            //if (minjump[i+j] > minjump[i]+1) {
                //minjump[i+j] = minjump[i]+1;
            //}
        //}
    //}
    //return minjump[n-1];
}

int main() {
    //int A[] = {2,4,8,1,0,8,3,0,7,9,9,8,3,1,7,3};
    //cout<<jump(A, sizeof(A)/sizeof(int))<<endl;
    //int A[5] = {2,1,1,1,1};
    //cout<<jump(A,5)<<endl;
    //int A[5] = {1,1,1,1,1};
    //cout<<jump(A,5)<<endl;
    //int A[3] = {3,2,1};
    //cout<<jump(A,3)<<endl;
    //int A[5] = {2,3,1,1,4};
    //cout<<jump(A, 5)<<endl;
    //int A[7] = {5,4,3,2,1,1,0};
    //cout<<jump(A, 7)<<endl;
    int i;
    int A[25002] = {0};
    A[25000] = 1;
    for (i = 0; i < 25000; i++) {
        A[i] = 25000 - i;
    }
    cout<<jump(A, 25002)<<endl;
}
