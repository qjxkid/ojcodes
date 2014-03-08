#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        int *longest = new int[len+1];
        memset(longest,0,sizeof(int)*(len+1));
        int start=1;
        char tmpch;
        int str[257] = {0};
        int maxlen=0;
        for(int i=1; i<=len; i++){
            tmpch = s[i-1];
            if(str[tmpch] == 0 || (str[tmpch]+1) < start){
                str[tmpch] = i;
                longest[i]=longest[i-1]+1;
            }
            else{
                start = (str[tmpch]+1);
                str[tmpch] = i;
                longest[i] = i - start + 1;
            }
            maxlen = longest[i] > maxlen ? longest[i] : maxlen;
        }
        delete longest;
        return maxlen;
    }
};

int main()
{
    Solution A;
    string abc="abcabcbb";
    cout << A.lengthOfLongestSubstring(abc) << endl;
    return 0;
}
