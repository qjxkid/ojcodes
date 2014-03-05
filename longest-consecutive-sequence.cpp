#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int longestConsecutive(vector<int> &num) {
    if (num.empty()) {
        return 0;
    }
    unordered_map<int, int> uii;
    int leftbound, rightbound;
    int tmplen;
    int maxlen = 1;
    for( auto i : num )  {
        if (uii[i] != 0) {
            continue;
        }
        uii[i] = 1;
        leftbound = uii[i-1];
        rightbound = uii[i+1];
        tmplen = uii[i-leftbound] = uii[i+rightbound] = 1 + leftbound + rightbound;
        if (tmplen > maxlen) {
            maxlen = tmplen;
        }
    }
    return maxlen;
}

int main() {
    vector<int> a;
    a.push_back(100);
    a.push_back(4);
    a.push_back(200);
    a.push_back(1);
    a.push_back(3);
    a.push_back(2);
    cout<<longestConsecutive(a)<<endl;
    return 0;
}
