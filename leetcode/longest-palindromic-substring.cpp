#include <iostream>
#include <cstring>
using namespace std;

bool table[1002][1002];

int checkTable(int i, int j) {
    if (i == j || j+1 == i) {
        return true;
    }
    return table[i][j];
}

int getLongest(string &s, int &index, int end) {
    int i;
    index = -1;
    for (i = 0; i < end; i++) {
        if (s[i] == s[end] && checkTable(i + 1, end - 1)) {
            if (index == -1) {
                index = i;
            }
            table[i][end] = true;
        }
    }
    if (index == -1) {
        return 1;
    }
    return (end - index + 1);
}

string longestPalindrome(string s) {
    int len = s.size();
    if (len == 0 || len == 1 || (len == 2 && s[0]==s[1])) {
        return s;
    }
    if (len == 2) {
        return s.substr(0,1);
    }
    int i;
    int longest = 1;
    int index = 0;
    int tmplen;
    int tmpindex;
    memset(table,0,sizeof(table));
    for (i = 1; i < len; i++) {
        tmplen = getLongest(s, tmpindex, i);
        if (tmplen > longest) {
            longest = tmplen;
            index = tmpindex;
        }
    }
    return s.substr(index,longest);
}


int main() {
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
cout<<longestPalindrome(s)<<endl;
    //string s;
    //while(1) {
        //cin>>s;
        //cout<<longestPalindrome(s)<<endl;
    //}
    return 0;
}
