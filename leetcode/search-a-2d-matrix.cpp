#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if (0 == matrix.size() || 0 == matrix[0].size()) return false;
    int rows = matrix.size();
    int cols = matrix[0].size();
    if (target < matrix[0][0] || target > matrix[rows-1][cols-1]) return false; 
    
    //row of interest
    int roi; 
    int bottom, top, mid;
    bottom = 0;
    top = rows - 1;
    mid = (bottom + top) / 2;
    while(bottom <= top) {
        if (target == matrix[mid][0]) {
            return true;
        }
        if (target < matrix[mid][0]) {
            top = mid - 1;
        }
        else {
            bottom = mid + 1;
        }
        mid = (bottom + top) / 2;
    }

    roi = mid;
    //search mid
    bottom = 0;
    top = cols - 1;
    mid = (bottom + top) / 2;
    while(bottom <= top) {
        if (target == matrix[roi][mid]) {
            return true;
        }
        if (target < matrix[roi][mid]) {
            top = mid - 1;
        }
        else {
            bottom = mid + 1;
        }
        mid = (bottom + top) / 2;
    }
    return false;
}

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(7);
    vector<int> c;
    c.push_back(10);
    c.push_back(30);
    c.push_back(50);
    c.push_back(70);
    vector<vector<int> > b;
    b.push_back(a);
    b.push_back(c);
    
    if (searchMatrix(b,90)) {
        cout<<"yes"<<endl;
    }
    else {
        cout<<"no"<<endl;
    }
    return 0;
}
