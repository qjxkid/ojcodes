#include <iostream>

using namespace std;

int singleNumber(int A[], int n) {
    int oldonce = 0;
    int oldtwice = 0;
    int newonce = 0;
    int newtwice = 0;
    int trice = 0;
    int i, tmp;
    for (i = 0; i < n; i++) {
        tmp = A[i];
        cout<<tmp<<" : ";
        newtwice |= (oldonce & tmp);
        newonce = (oldonce ^ tmp);
        trice = oldtwice & newonce;
        cout<<trice<<" : ";
        cout<<oldonce<<" "<<oldtwice<<" "<<newonce<<" "<<newtwice<<endl; 
        trice = ~trice;
        newtwice = newtwice & trice;
        newonce = newonce & trice;
        oldonce = newonce;
        oldtwice = newtwice;
    }
    return oldonce;
}

int main() {
    //cout<<~1<<endl;
    //int A[] = {1,1,1,2,2,2,3,3,3,4,4,4,88,88,88,99,99,99,100};
    //int A[] = {2,2,3,2};
    //int A[] = {1,0,1,0,1,0,9};
    int A[] = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
    //int A[] = {2,2,1,1,3,1,3,3,4,2};
    cout<<singleNumber(A,sizeof(A)/sizeof(int));
    return 0;
}
