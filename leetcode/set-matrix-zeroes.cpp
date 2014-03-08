#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int> > &matrix){
	bool row1st0 = false;
	bool col1st0 = false;
	int rows = matrix.size();
	if (rows == 0) {
		return;
	}
	int cols = matrix[0].size();
	if (cols == 0) {
		return;
	}
	int i,j;

	//record the first row and first line's 0 status
	for (i = 0; i < rows; i++) {
		if (matrix[i][0] == 0) {
			col1st0 = true;
			break;
		}
	}
	for (i = 0; i < cols; i++) {
		if (matrix[0][i] == 0) {
			row1st0 = true;
			break;
		}
	}
	//record 0 points' info
	for (i = 1; i < rows; i++) {
		for (j = 1; j < cols; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	//set 0
	for (i = 1; i < rows; i++) {
		if (matrix[i][0] == 0) {
			for (j = 1; j < cols; j++) {
				matrix[i][j] = 0;
			}
		}
	}
	for (i = 1; i < cols; i++) {
		if (matrix[0][i] == 0) {
			for (j = 1; j < rows; j++) {
				matrix[j][i] = 0;
			}
		}
	}

//test
cout<<"************************\n";
for (i = 0; i < cols; i++) {
	cout<<matrix[0][i]<<" ";
}
cout<<endl;
cout<<"************************\n";
	if (row1st0) {
		for (i = 0; i < cols; i++) {
			matrix[0][i] = 0;
		}
	}
	if (col1st0) {
		for (i = 0; i < rows; i++) {
			matrix[i][0] = 0;
		}
	}
}

int main(){
	vector<vector<int> > A;
	vector<int> tmp;
	tmp.push_back(0);
	tmp.push_back(0);
	tmp.push_back(0);
	tmp.push_back(5);
	A.push_back(tmp);
	tmp.clear();
	tmp.push_back(4);
	tmp.push_back(3);
	tmp.push_back(1);
	tmp.push_back(4);
	A.push_back(tmp);
	tmp.clear();
	tmp.push_back(0);
	tmp.push_back(1);
	tmp.push_back(1);
	tmp.push_back(4);
	A.push_back(tmp);
	tmp.clear();
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(1);
	tmp.push_back(3);
	A.push_back(tmp);
	tmp.clear();
	tmp.push_back(0);
	tmp.push_back(0);
	tmp.push_back(1);
	tmp.push_back(1);
	A.push_back(tmp);

	setZeroes(A);
	int i,j;
	int rows = A.size();
	int cols = A[0].size();
	for(i = 0; i < rows; i++){
		for (j = 0; j < cols; j++) {
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
