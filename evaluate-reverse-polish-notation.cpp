#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

int evalRPN(vector<string> &tokens) {
    stack<int> num;
    int i;
    int len = tokens.size();
    int x,y;
    for (i = 0; i < len; i++) {
        if ( strcmp(tokens.at(i).c_str(), "+") == 0) {
            x = num.top();
            num.pop();
            y = num.top();
            num.pop();
            num.push(x+y);
        }
        else if( strcmp(tokens.at(i).c_str(), "-") == 0) {
            x = num.top();
            num.pop();
            y = num.top();
            num.pop();
            num.push(y-x);
        }
        else if( strcmp(tokens.at(i).c_str(), "*") == 0) {
            x = num.top();
            num.pop();
            y = num.top();
            num.pop();
            num.push(x*y);
        }
        else if( strcmp(tokens.at(i).c_str(), "/") == 0) {
            x = num.top();
            num.pop();
            y = num.top();
            num.pop();
            num.push(y/x);
        }
        else {
            num.push(atoi(tokens.at(i).c_str()));
        }
    }
    return num.top();
}

int main() {
    vector<string> tokens;
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");
    cout<<evalRPN(tokens)<<endl;
    return 0;
}
