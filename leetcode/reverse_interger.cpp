#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

void reversstr(char * str, int len){
    int i=0;
    int j=len-1;
    char tmp;
    while(j>i){
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
}

int reverseint(int x){
    char tmpnumstr[12];
    char numstrwithoutsign[12];
    bool negativeflag = false;
    int result;
    sprintf(tmpnumstr,"%d",x);
    if (tmpnumstr[0] == '-'){
        negativeflag = true;
        strcpy(numstrwithoutsign, &(tmpnumstr[1]));
    }
    else{
        strcpy(numstrwithoutsign, tmpnumstr);
    }
    reversstr(numstrwithoutsign, strlen(numstrwithoutsign));
    if (negativeflag){
        strcpy(&(tmpnumstr[1]), numstrwithoutsign);
    }
    else{
        strcpy(tmpnumstr, numstrwithoutsign);
    }
    result = atoi(tmpnumstr);
    return result;
}
int main(){
    cout<<reverseint(123)<<endl;
    cout<<reverseint(-123)<<endl;
    return 0;
}
