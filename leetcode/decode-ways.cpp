#include <iostream>

using namespace std;

int numDecodings(string s) {
    string::size_type ten = s.find("10");
    while(ten != string::npos) {
        s.replace(ten, 2, "a");
        ten = s.find("10");
    }
    string::size_type twenty = s.find("20");
    while(twenty != string::npos) {
        s.replace(twenty, 2, "b");
        twenty = s.find("20");
    }
    string::size_type zero = s.find("0");
    if (zero != string::npos) return 0;
    int len = s.size();
    if (0 == len) return 0;
    if (1 == len && s[0] != '0') return 1;
    if (1 == len && s[0] == '0') return 0;
    if (2 == len) {
        if (s[0] == '1' && s[1] <= '9' || s[0] == '2' && s[1] <= '6') return 2;
        else return 1;
    }
    int way2 = 1, way1, way0;
    if (s[len-2] == '1' && s[len-1] <= '9'|| s[len-2] == '2' && s[len-1] <= '6') way1 = 2;
    else way1 = 1;
    int i;
    for(i=len-3; i>=0; i--){
        if (s[i] == '1' && s[i+1] <= '9' || s[i] == '2' && s[i+1] <= '6') way0 = way1 + way2;
        else way0 = way1;
        way2 = way1;
        way1 = way0;
    }
    return way0;
}

int main(){
    cout<<numDecodings("110")<<endl;
}
