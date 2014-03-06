//overlay func for kmp algorithm
#include <iostream>
#include <string>

using namespace std;

void compute_overlay(const string& pattern) {
    const int pattern_length = pattern.size();
    int *overlay_function = new int[pattern_length];
    int index;
    int i;
    overlay_function[0] = -1;
    for (i = 1; i < pattern_length; i++) {
        index = overlay_function[i-1];
        //store previous fail position k to index
        
        while(index >=0 && pattern[i]!=pattern[index+1]) {
            // there is no "+1" meaning going back one key. And func tells matching to the pattern[index], then check pattern[index+1]...
            index = overlay_function[index]; 
        }
        // matches..
        if (pattern[i] == pattern[index+1]) {
            overlay_function[i] = index + 1;
        }
        // doesn't match..
        else {
            overlay_function[i] = -1;
        }
    }
    for(i=0;i<pattern_length;++i)
    {
        cout<<overlay_function[i]<<endl;
    }
    delete[] overlay_function;
}
int main()
{
    string pattern = "abaabcaba";
    compute_overlay(pattern);
    return 0;
}
