#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int search(int A[], int n, int target){
	int flag = -1;
	if (target == A[0]) {
		return 0;
	}
	if (target < A[0]) {
		flag = 1;
	}
	else {
		flag = -1;
	}
	int bottom = 0, top = n-1;
	int mid = (top + bottom)/2;
	while(top >= bottom){
		if (target == A[mid]) {
			return mid;
		}
		if (target > A[mid]) {
			if (flag == 1) {
				bottom = mid + 1;
			}
			else {
				if (A[mid] >= A[0]) {
					bottom = mid + 1;
				}
				if (A[mid] < A[0]) {
					top = mid - 1;
				}
			}
		}
		if (target < A[mid]) {
			if (flag == 1) {
				if (A[mid] >= A[0]) {
					bottom = mid + 1;
				}
				if (A[mid] < A[0]) {
					top = mid - 1;
				}
			}
			else {
				top = mid - 1;
			}
		}
		mid = (top + bottom)/2;
	}
	return -1;
}

int main(){
	int A[7] = {4,5,6,7,0,1,2};
	cout<<search(A,7,6)<<endl;
	return 0;
}
