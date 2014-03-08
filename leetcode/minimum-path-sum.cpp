#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int> > &grid){
    // init
    int rows = grid.size();
    if (rows == 0) {
        return 0;
    }
    int cols = grid[0].size();
    if (cols == 0) {
        return 0;
    }
    vector<int> prerow(cols), currrow(cols);
    int i,j;
    prerow[0] = grid[0][0];
    for (i = 1; i < cols; i++) {
        prerow[i] = prerow[i-1] + grid[0][i];
    }

    for (i = 1; i < rows; i++) {
        currrow[0] = prerow[0] + grid[i][0];
        for (j = 1; j < cols; j++) {
            currrow[j] = grid[i][j] + min(currrow[j-1], prerow[j]);
        }
        swap(currrow,prerow);
    }
    return prerow[cols-1];
}

int main(){
    vector<vector<int> > test;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    vector<int> c;
    c.push_back(1);
    c.push_back(1);
    c.push_back(1);
    test.push_back(a);
    test.push_back(b);
    test.push_back(c);
    cout<<minPathSum(test);
    return 0;
}
