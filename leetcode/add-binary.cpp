#include <iostream>
#include <stack>

using namespace std;

string addBinary(string a, string b) {
    stack<char> a_s;
    stack<char> b_s;
    bool carry = false;
    stack<char> c_s;
    char tmpa, tmpb;
    for ( auto tmp : a ) {
        a_s.push(tmp);
    }
    for ( auto tmp : b ) {
        b_s.push(tmp);
    }
    while (!a_s.empty() && !b_s.empty()) {
        tmpa = a_s.top();
        a_s.pop();
        tmpb = b_s.top();
        b_s.pop();
        if (tmpa == '1') {
            if (carry) {
                c_s.push(tmpb);
            }
            else {
                if (tmpb == '1') {
                    c_s.push('0');
                    carry = true;
                }
                else {
                    c_s.push('1');
                }
            }
        }
        else {
            if(!carry) {
                c_s.push(tmpb);
            }
            else {
                if (tmpb == '1') {
                    c_s.push('0');
                }
                else {
                    c_s.push('1');
                    carry = false;
                }
            }
        }
    }
    while (!a_s.empty()) {
        tmpa = a_s.top();
        a_s.pop();
        if (!carry) {
            c_s.push(tmpa);
        }
        else {
            if (tmpa == '1') {
                c_s.push('0');
            }
            else {
                c_s.push('1');
                carry = false;
            }
        }
    }
    while (!b_s.empty()) {
        tmpb = b_s.top();
        b_s.pop();
        if (!carry) {
            c_s.push(tmpb);
        }
        else {
            if (tmpb == '1') {
                c_s.push('0');
            }
            else {
                c_s.push('1');
                carry = false;
            }
        }
    }
    if (carry) {
        c_s.push('1');
    }
    string ans;
    while (!c_s.empty()) {
        ans.push_back(c_s.top());
        c_s.pop();
    }
    return ans;
}

int main() {
    string a("111");
    string b("11");
    cout<<addBinary(a,b)<<endl;
    return 0;
}
