#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
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

stack<string> strstack;

void judge(string &s, unordered_set<string> &dict, int index, vector<string> &result) {
    if (index > s.size()) {
        return ;
    }
    if (index == s.size()) {
        stack<string> tmpstack;
        string tmpstr;
        while (!strstack.empty()) {
            tmpstack.push(strstack.top());
            strstack.pop();
        }
        while (!tmpstack.empty()) {
            strstack.push(tmpstack.top());
            tmpstr += tmpstack.top();
            tmpstack.pop();
            if(!tmpstack.empty()) tmpstr += " ";
        }
        //cout<<tmpstr<<endl;
        result.push_back(tmpstr);
    }
    unordered_set<string>::iterator it;
    for (it = dict.begin(); it != dict.end(); it++) {
        if (it->size() + index > s.size()) {
            continue;
        }
        if (strCmp(s, *it, index)) {
            strstack.push(*it);
            judge(s, dict, index+(it->size()), result); 
            strstack.pop();
        }
    }
}

vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<string> result;
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
            return result;
        }
    }
    judge(s, dict, 0, result);
    return result;
}

int main() {
    //string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    string s("catsanddog");
    unordered_set<string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    vector<string> result = wordBreak(s, dict);
    int len = result.size();
    int i;
    for (i = 0; i < len; i++) {
        cout<<result[i]<<"!"<<endl;
    }
    //if(wordBreak(s, dict)){
        //cout<<"yes"<<endl;
    //}
    //else {
        //cout<<"no"<<endl;
    //}
    return 0;
}
