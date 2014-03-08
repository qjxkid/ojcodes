#include <iostream>
#include <cstring>

using namespace std;


int uniquePaths(int m, int n) {
	static int paths[110][110] = {0};
	paths[1][1] = 1;

	if (paths[m][n] == 0) {
		if (m == 1) {
			paths[m][n] = uniquePaths(m, n-1);
		}
		if (n == 1) {
			paths[m][n] = uniquePaths(m-1, n);
		}
		if (m > 1 && n > 1) {
			paths[m][n] = uniquePaths(m-1, n) + uniquePaths(m, n-1);
		}
	}
	return paths[m][n];
}

int main(){
	cout << uniquePaths(3,7)<<endl;
	return 0;
}
