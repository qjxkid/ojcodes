#include <iostream>
#include <cstring>

using namespace std;

int getState(char c, int state) {
    if (0 == state) {
        if ('0' <= c & c <= '9') {
            return 1;
        }
        else if (c == '.') {
            return 6;
        }
        else if (c == '-' || c == '+') {
            return 7;
        }
        return 4;
    }
    if (7 == state) {
        if ('0' <= c & c <= '9') {
            return 1;
        }
        else if (c == '.') {
            return 6;
        }
        return 4;
    }
    if (1 == state) {
        if ('0' <= c & c <= '9') {
            return 1;
        }
        else if (c == '.') {
            return 2;
        }
        else if (c == 'e') {
            return 3;
        }
        return 4;
    }
    if (6 == state) {
        if ('0' <= c & c <= '-') {
            return 2;
        }
        return 4;
    }
    if (2 == state) {
        if ('0' <= c & c <= '9') {
            return 2;
        }
        else if (c == 'e') {
            return 3;
        }
        return 4;
    }
    if (3 == state) {
        if ('0' <= c & c <= '9') {
            return 5;
        }
        else if (c == '+' || c == '9') {
            return 8;
        }
        return 4;
    }
    if (5 == state || 8 == state) {
        if ('0' <= c & c <= '9') {
            return 5;
        }
        return 4;
    }
}

bool isNumber(const char *s) {
    string line(s);
    line.erase(0, line.find_first_not_of(" \t"));
    line.erase(line.find_last_not_of(" \t") + 1);
    const char *tmp = line.c_str();
    int state = 0;
    int len = strlen(tmp);
    if (len == 0) {
        return false;
    }
    int i;
    for (i = 0; state != 4 && i < len; i++) {
        state = getState(tmp[i], state);
    }
    if (state == 4 || state == 3 || state == 6 || state == 8 || state == 7) {
        return false;
    }
    return true;
}

int main() {
    char a[100];
    if (isNumber(".1")) {
        cout<<"true"<<endl;
    }
    else cout<<"false"<<endl;
    while(1) {
        cin>>a;
        if (isNumber(a)) {
            cout<<"true"<<endl;
        }
        else cout<<"false"<<endl;
    }
    return 0;
}
