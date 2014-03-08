#include <iostream>
using namespace std;

void sortColors(int A[], int n){
	int i,j;
	int red=0;
	int white=0;
	int blue=0;
	for (i = 0; i < n; i++) {
		switch(A[i]){
			case 0:
				red++;
				break;
			case 1:
				white++;
				break;
			case 2:
				blue++;
				break;
		}
	}
	for (i = 0; i < red; i++) {
		A[i] = 0;
	}
	for (j = 0; j < white; j++, i++) {
		A[i] = 1;
	}
	for (j = 0; j < blue; j++, i++) {
		A[i] = 2;
	}
}

int main(){
	int A[9]={0,1,2,0,1,2,0,1,2};
	sortColors(A,9);
	for (int i = 0; i < 9; i++) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}
