#include <iostream>
#include <cstring>

using namespace std;

int * compute_overlay(const char * pattern) {
    int pattern_length = strlen(pattern);
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
    return overlay_function;
}


char *strStr(char *haystack, char *needle) {
    int target_len = strlen(haystack);
    int pattern_len = strlen(needle);
    int *overlay_value = compute_overlay(needle);
    int pos;
    
    //match algorithm
    int pattern_index = 0;
    int target_index = 0;
    while(pattern_index < pattern_len && target_index < target_len) {
        if (haystack[target_index] == needle[pattern_index]) {
            target_index++;
            pattern_index++;
        }
        else if (pattern_index == 0) {
            target_index++;
        }
        else {
            pattern_index = overlay_value[pattern_index - 1] + 1;
        }
    }
    if (pattern_len == pattern_index) {
        pos = target_index - pattern_index;
        return &(haystack[pos]);
    }
    else {
        return NULL;
    }
}

int main() {
    char a[] = "mississippi";
    char b[] = "issip";
    char *c = strStr(a, b);
    cout<<c<<endl;
    
}
