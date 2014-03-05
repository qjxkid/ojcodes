#include <iostream>

using namespace std;

int lengthOfLastWord(const char *s) {
    string str(s);
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    
    if (str.length() == 0) {
        return 0;
    }

    return (str.length() - str.find_last_of(" ") - 1);
}

int main() {
    cout<<lengthOfLastWord("  Hello world  ")<<endl;
    
}
