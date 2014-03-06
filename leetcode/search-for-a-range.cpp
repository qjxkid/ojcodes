#include <iostream>
#include <vector>

using namespace std;

int getTargetEnd(int A[], int bottom, int top, int target) {
    int mid = (bottom + top)/2;
    if (A[top] == target) {
        return top;
    }
    while (A[mid] == target) {
        bottom = mid + 1;
        mid = (top + bottom)/2;
    }
    while (A[mid] != target) {
        top = mid - 1;
        mid = (top + bottom)/2;
    }
    mid++;
    while (A[mid] == target) {
        mid++;
    }
    return mid-1;
}

int getTargetStart(int A[], int bottom, int top, int target) {
    int mid = (bottom + top)/2;
    if (A[bottom] == target) {
        return bottom;
    }
    while (A[mid] == target) {
        top = mid - 1;
        mid = (top + bottom)/2;
    }
    while (bottom < top && A[mid] != target) {
        bottom = mid + 1;
        mid = (top + bottom)/2;
    }
    if (bottom == top) {
        while (A[mid] != target) {
            mid++;
        }
    }
    mid--;
    while (A[mid] == target) {
        mid--;
    }
    return mid+1;
}

vector<int> searchRange(int A[], int n, int target) {
    int top = n-1;
    int bottom = 0;
    int mid = (top + bottom)/2;
    int i = 0;
    vector<int> ans;
    if (0 == n || target < A[0] || target > A[n-1]) {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    if (n == 1) {
        if (A[0] == target) {
            ans.push_back(0);
            ans.push_back(0);
            return ans;
        }
        else {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
    }
    if (A[0] == target) {
        ans.push_back(0);
        ans.push_back( getTargetEnd(A, 0, n-1, target) );
        return ans;
    }
    if (A[n-1] == target) {
        ans.push_back( getTargetStart(A, 0, n-1, target) );
        ans.push_back(n-1);
        return ans;
    }
    while (bottom < top) {
        if (A[mid] < target) {
            bottom = mid + 1;
            mid = (bottom + top)/2;
        }
        else if (A[mid] > target) {
            top = mid - 1;
            mid = (bottom + top)/2;
        }
        else {
            ans.push_back( getTargetStart(A, bottom, mid, target) );
            ans.push_back( getTargetEnd(A, mid, top, target) );
            return ans;
        }
    }
    if (A[mid] == target) {
        ans.push_back(mid);
        ans.push_back(mid);
        return ans;
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}

int main() {
    //int A[] = {-1,-2,-3};
    //int A[] = {-1,0,2,3};
    //int A[] = {-1,0,1,2,3};
    //int A[] = {2,3,4,5,6,7,9};
    //int A[] = {1,2,2};
    //int A[] = {5,7,7,8,8,10};
    int A[] = {0,1,1,2,2,2,2,2,2,2,2,2,3,4,4};
    //int A[] = {1,1,1,2};

    //int A[] = {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3};
    vector<int> tmp = searchRange(A, sizeof(A)/sizeof(int), 3);
    cout<<tmp[0]<<endl<<tmp[1]<<endl;
    return 0;
}
