#include <iostream>

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
}

int main() {
    int A[] = {2,4,8,1,0,8,3,0,7,9,9,8,3,1,7,3};
    cout<<jump(A,sizeof(A)/sizeof(int))<<endl;

}
