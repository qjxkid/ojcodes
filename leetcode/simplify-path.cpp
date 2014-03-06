#include <iostream>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;

string simplifyPath(string path) {
    int len = path.size();
    if (len == 1) {
        return "/";
    }
    queue<string> strqueue;
    stack<string> pathstack;
    stack<string> pathstack2;
    int i;
    int dirlen = 0;
    string tmpstr;
    string result;
    for (i = 1; i < len; i++) {
        if (path[i] != '/') {
            dirlen++;
        }
        else {
            if (dirlen != 0) {
                strqueue.push(path.substr(i - dirlen, dirlen));
                //cout<<path.substr(i - dirlen,dirlen)<<endl;
            }
            dirlen = 0;
        }
    }
    if (dirlen != 0) {
        strqueue.push(path.substr(i - dirlen, dirlen));
    }
    while (!strqueue.empty()) {
        tmpstr = strqueue.front();
        //cout<<tmpstr<<endl;
        if (strcmp(tmpstr.c_str(), "..") == 0) {
            if (pathstack.empty()) {
                return "/";
            }
            pathstack.pop();
        }
        else if (strcmp(tmpstr.c_str(), ".") != 0) {
            pathstack.push(tmpstr);
        }
        strqueue.pop();
    }
    if (pathstack.empty()) {
        return "/";
    }
    while (!pathstack.empty()) {
        tmpstr = pathstack.top();
        pathstack.pop();
        pathstack2.push(tmpstr);
    }
    while (!pathstack2.empty()) {
        result += "/" + pathstack2.top();
        pathstack2.pop();
    }
    return result;
}


int main() {
    //string s("/a/./b/../..//c/");
    //string s("/../");
    //string s("/home//foo/");
    //string s("/...");
    string s("/home/foo/.ssh/../.ssh2/authorized_keys/");
    cout<<simplifyPath(s);
    return 0;
}
