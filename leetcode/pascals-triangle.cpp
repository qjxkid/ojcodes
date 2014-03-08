#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<vector<int> > generate(int numRows){
    vector<vector<int> > result;
    if (numRows == 0) return result;
    vector<int> tmp;
    tmp.push_back(1);
    result.push_back(tmp);
    int i,j;
    for(i=1; i<numRows; i++){
        tmp.clear();
        tmp.push_back(1);
        for(j=1; j<i; j++){
            tmp.push_back(result[i-1].at(j-1) + result[i-1].at(j));
        }
        tmp.push_back(1);
        result.push_back(tmp);
    }
    return result;
}

int main(){
    vector<vector<int> > a = generate(5);
    int len1,len2;
    int i,j;
    len1 = a.size();
    for(i=0; i<len1; i++){
        len2 = a[i].size();
        for(j=0; j<len2; j++){
            cout<<a[i].at(j)<<" ";
//            cout<<a[i].size()<<endl;
        }
        cout<<endl;
    }
//    vector<vector<int> > a;
//    vector<int> tmp;
//    tmp.push_back(1);
//    a.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(2);
//    tmp.push_back(3);
//    a.push_back(tmp);
//    int len1,len2;
//    len1 = a.size();
//    int i,j;
//    for(i=0; i<len1; i++){
//        len2 = a[i].size();
//        for(j=0; j<len2; j++){
//            cout<<a[i][j];
//        }
//        cout<<endl;
//    }
    return 0;
}
