#include <iostream>
class Solution {
private:
    int findSmaller(int C[], int o1, int o2, int v){
        //use the binary search to find how many numbers are smaller than v in array C.
        int bottom = o1;
        int top = o2;
        int mid = (o1+o2)/2;
        while(bottom < top){
            mid = (bottom + top)/2;
            if(v == C[mid])
                return (mid-o1);
            else if(v > C[mid])
                bottom = mid + 1;
            else
                top = mid - 1;
        }
        return (bottom-o1);
    }
    double singleFind(int A[], int m1, int m2, int p, int q){
        return ((double)A[m1+p]+(double)A[m1+q])/2;
    }
    double findValue(int A[], int m1, int m2, int B[], int n1, int n2, int p, int q){
        //return the (pth + qth)/2 of all numbers.

        //needed?
        int *C;
        int o1,o2;
        if ((n2-n1)>(m2-m1)){
            o1 = m1;
            o2 = m2;
            m1 = n1;
            m2 = n2;
            n1 = o1;
            n2 = o2;
            C = A;
            A = B;
            B = C;
        }
        int fmid = A[(m2+m1)/2];
        int small1 = (m2+m1)/2 - m1;
        int small2 = findSmaller(B,n1,n2,fmid);
        if ((small1+small2) < p){
            p = p-small1-small2-1;
            q = q-small1-small2-1;
            if( ((m2+m1)/2+1) > m2)
                return singleFind(B,n1,n2,p,q);
            return findValue(A,(m2+m1)/2+1,m2,B,n1,n2,p,q);
        }
        else if((small1+small2) > q){
            if ( ((m2+m1)/2-1) < m1)
                return singleFind(B,n1,n2,p,q);
            return findValue(A,m1,(m2+m1)/2-1,B,n1,n2,p,q);
        }
        else if( (small1+small2) == p ){
            if (p==q)
                return fmid;
            else{
                if ((m2+m1)/2 == m2)
                    return ((double)fmid + (double)B[n1+small2])/2;
                else{
                    int sec = A[(m2+m1)/2+1] < B[n1+small2] ? A[(m2+m1)/2+1] : B[n1+small2];
                    return ((double)fmid + (double)sec)/2;
                }
            }
        }
        else{
            // already the bigger one, need to find a smaller num.
            if (p==q)
                return fmid;
            else{
                if (B[n1+small2] == fmid)
                if ( (m2+m1)/2 == m1 ){
                        return ((double)fmid + (double)B[n1+small2-1])/2;
                }
                else{
                    int sec = A[(m2+m1)/2-1] > B[n1+small2-1] ? A[(m2+m1)/2-1] : B[n1+small2-1];
                    return ((double)fmid + (double)sec)/2;
                }
            }
        }
    }
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if((m+n) % 2)
            return findValue(A,0,m-1,B,0,n-1, (m+n)/2, (m+n)/2);
        else
            return findValue(A,0,m-1,B,0,n-1, (m+n)/2-1, (m+n)/2);
    }
};
int main(){
    Solution nn;
    int A[]={1,2,3,4};
    int B[]={5,6,7,8};
    std::cout<<nn.findMedianSortedArrays(A,4,B,4)<<std::endl;
    return 0;
}
