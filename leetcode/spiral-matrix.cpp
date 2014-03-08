#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix){
	vector<int> result;
	int rows = matrix.size();
	if (rows == 0) {
		return result;
	}
	int cols = matrix[0].size();
	if (cols == 0) {
		return result;
	}
	cout<<"rows = "<<rows<<endl;
	int colstart = 0;
	int colend = cols - 1;
	int rowstart = 0;
	int rowend = rows - 1;
	int i,j;
	while( (rowend >= rowstart) && (colend >= colstart)){
		for (i = colstart; i <= colend; i++) {
			result.push_back(matrix[rowstart][i]);
		}
		//judgement
		if (rowend < rowstart + 1) {
			break;
		}
		for (i = rowstart + 1; i <= rowend; i++) {
			result.push_back(matrix[i][colend]);
		}
		//judgement
		if (colend < colstart + 1) {
			break;
		}
		for (i = colend - 1; i >= colstart; i--) {
			result.push_back(matrix[rowend][i]);
		}
		//judgement
		if (rowend - 1 < rowstart + 1) {
			break;
		}
		for (i = rowend - 1; i > rowstart; i--) {
			result.push_back(matrix[i][colstart]);
		}
		rowstart++;
		rowend--;
		colstart++;
		colend--;
	}
	return result;
}

int main(){
	vector<vector<int> > test;
	vector<int> tmp;
	tmp.push_back(1);
	//tmp.push_back(2);
	//tmp.push_back(3);
	test.push_back(tmp);
	tmp.clear();
	tmp.push_back(4);
	//tmp.push_back(5);
	//tmp.push_back(6);
	//test.push_back(tmp);
	//tmp.clear();
	//tmp.push_back(7);
	//tmp.push_back(8);
	//tmp.push_back(9);
	test.push_back(tmp);
	tmp.clear();
	tmp = spiralOrder(test);
	for(int i=0; i<tmp.size(); i++)
		cout<<tmp[i]<<" ";
	cout<<"\n";
	return 0;
}
