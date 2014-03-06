#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {
    int len = triangle.size();
    if (len == 0) {
        return 0;
    }
    if (len == 1) {
        return triangle[0][0];
    }
    int *rowmin = new int[len];
    int i,j;
    for (i = 0; i < len; i++) {
        rowmin[i] = triangle[len-1][i];
    }
    for (i = len-2; i >= 0; i--) {
        for (j = 0; j <= i; j++) {
            rowmin[j] = min(rowmin[j], rowmin[j+1]) + triangle[i][j];
        }
    }
    int result = rowmin[0];
    delete [] rowmin;
    return result;
}

int main() {
    vector<int> tmp;
    vector<vector<int> >triangle;
    tmp.push_back(2);
    triangle.push_back(tmp);
    tmp.clear();
    tmp.push_back(3);
    tmp.push_back(4);
    triangle.push_back(tmp);
    tmp.clear();
    tmp.push_back(6);
    tmp.push_back(5);
    tmp.push_back(7);
    triangle.push_back(tmp);
    tmp.clear();
    tmp.push_back(7);
    tmp.push_back(1);
    tmp.push_back(8);
    tmp.push_back(3);
    triangle.push_back(tmp);
    tmp.clear();

    cout<<minimumTotal(triangle)<<endl;
    return 0;
}
