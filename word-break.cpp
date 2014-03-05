#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool strCmp(string &s, string pattern, int index) {
    int i=0;
    int len = pattern.size();
    while(i<len && s[index+i] == pattern[i]) {
        i++;
    }
    if (i == len) {
        return true;
    }
    return false;
}

bool judge(string &s, unordered_set<string> &dict, int index) {
    if (index > s.size()) {
        return false;
    }
    if (index == s.size()) {
        return true;
    }
    unordered_set<string>::iterator it;
    for (it = dict.begin(); it != dict.end(); it++) {
        if (it->size() + index > s.size()) {
            continue;
        }
        if (strCmp(s, *it, index)) {
            if (judge(s, dict, index+(it->size()))) {
                return true;
            }
        }
    }
    return false;
}

bool wordBreak(string s, unordered_set<string> &dict) {
    //unordered_map<char, int> keytable;
    int keytable[60] = {0};
    int len;
    unordered_set<string>::iterator it;
    int i;
    for (it = dict.begin(); it != dict.end(); it++) {
        len = it->size();
        for (i = 0; i < len; i++) {
            if (keytable[(it->at(i))-'a'] == 0)
                keytable[it->at(i)-'a'] = 1;
        }
    }
    len = s.size();
    for (i = 0; i < len; i++) {
        if (keytable[s[i]-'a'] == 0) {
            return false;
        }
    }
    if (judge(s,dict,0)) {
        return true;
    }
    return false;
}

int main() {
    //string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    string s("ab");
    unordered_set<string> dict;
    dict.insert("b");
    dict.insert("a");
    if(wordBreak(s, dict)){
        cout<<"yes"<<endl;
    }
    else {
        cout<<"no"<<endl;
    }
    return 0;
}
