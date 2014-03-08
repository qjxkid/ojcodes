#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//int getNum(int n, int A[]){
//    if (n==1) return 1;
//    if (n==2) return 2;
//    if (A[n] == 0){
//        A[n] = getNum(n-1, A) + getNum(n-2, A);
//    }
//    return A[n];
//}

int climbStairs(int n){
    static int A[100000] = {0};
    if (n==1) return 1;
    if (n==2) return 2;
    if (A[n] == 0){
        A[n] = climbStairs(n-1) + climbStairs(n-2);
    }
    return A[n];
}

int main(){
    cout<<climbStairs(3);
    return 0;
}
