#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n, vector<vector<int> > &obstacleGrid) {
    static int paths[110][110] = {0};
    paths[1][1] = 1;
    if (obstacleGrid[m-1][n-1]) return 0;
    if (paths[m][n] == 0) {
        if (m == 1) {
            if (obstacleGrid[m-1][n-2]) {
                paths[m][n] = 0;
                return 0;
            } 
            paths[m][n] = uniquePaths(m, n-1, obstacleGrid);
        }
        if (n == 1) {
            if (obstacleGrid[m-2][n-1]) {
                paths[m][n] = 0;
                return 0;
            } 
            paths[m][n] = uniquePaths(m-1, n, obstacleGrid);
        }
        if (m > 1 && n > 1) {
            if (obstacleGrid[m-1][n-2] !=1 && obstacleGrid[m-2][n-1] != 1) {
                paths[m][n] = uniquePaths(m-1, n, obstacleGrid) + uniquePaths(m, n-1, obstacleGrid
);
            }
            else if (obstacleGrid[m-1][n-2]) {
                paths[m][n] = uniquePaths(m-1, n, obstacleGrid);
            }         
            else {
                paths[m][n] = uniquePaths(m, n-1, obstacleGrid);
            }
        }
    }
    return paths[m][n];
}
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int m = obstacleGrid.size();
    if (m == 0) {
        return 0;
    }
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }
    return uniquePaths(m, n, obstacleGrid);
}
int main() {
    vector<int> a;
    a.push_back(0);
    a.push_back(0);
    vector<vector<int> > b;
    b.push_back(a);
    a.clear();
    a.push_back(1);
    a.push_back(0);
    b.push_back(a);
    cout<<uniquePathsWithObstacles(b)<<endl;
    return 0;
}
