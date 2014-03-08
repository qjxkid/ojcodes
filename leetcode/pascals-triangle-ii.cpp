#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> getRow(int rowIndex) {
    rowIndex++;
    vector<int> tmp1;
    vector<int> tmp2;
    tmp1.push_back(1);
    if (rowIndex == 1) return tmp1;
    tmp1.clear();
    int i,j;
    for(i=1; i<rowIndex; i++){
        tmp1.push_back(1);
        for(j=1; j<i; j++){
            tmp1.push_back(tmp2.at(j-1) + tmp2.at(j));
        }
        tmp1.push_back(1);
        tmp2.clear();
        swap(tmp1,tmp2);
    }
    return tmp2;
}
int main(){
    vector<int > row = getRow(2);
    int len = row.size();
    for(int i=0; i<len; i++){
        cout<<row[i]<<" ";
    }
    return 0;
}
