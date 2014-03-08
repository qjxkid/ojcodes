#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    int a[100000] = {-1};
    string str;

    int dfs(int pos) {
        if (a[pos] != -1) {
            return a[pos];
        }
        if (pos == str.size() - 1) {
            if (str[pos] == '0') return a[pos] = 0;
            else return a[pos] = 1;
        }
        if (pos == str.size()) return a[pos] = 1;
        if (str[pos] == '0') {
            return a[pos] = 0;
        } else if (str[pos] == '1') {
            return a[pos] = dfs(pos + 1) + dfs(pos + 2);
        } else if (str[pos] == '2') {
            if (str[pos + 1] > '6') {
                return a[pos] = dfs(pos + 1);
            } else {
                return a[pos] = dfs(pos + 1) + dfs(pos + 2);
            }
        } else {
            return a[pos] = dfs(pos + 1);
        }
    }
    int numDecodings(string s) {
        str = s;
        memset(a,-1,sizeof(a));
        if (s.size() == 0) return 0;
        return dfs(0);
    }
};
int main(){
    Solution s;
    cout<<s.numDecodings("10")<<endl;
    return 0;
}
