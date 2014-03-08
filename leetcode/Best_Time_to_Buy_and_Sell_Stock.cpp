#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int> &prices) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
//    int daysnum = prices.size();
//    if (daysnum == 0 || daysnum == 1)
//        return 0;
//    int minprice = prices[0];
//    int maxprofit = 0;
//    for(int i=1; i<daysnum; i++){
//        minprice = minprice < prices[i] ? minprice : prices[i];
//        maxprofit = (prices[i] - minprice) > maxprofit ? (prices[i] - minprice) : maxprofit;
//    }
//    return maxprofit;


//    int daysnum = prices.size();
//    if (daysnum == 0 || daysnum == 1)
//        return 0;
//    int minprice = prices[0];
//    int tmpprofit = 0;
//    int maxprofit = 0;
//    int currentmaxprice = minprice;
//    for(int i=1; i<daysnum; i++){
//        if (currentmaxprice <= prices[i]){
//            tmpprofit = (prices[i] - minprice) > tmpprofit ? (prices[i] - minprice) : tmpprofit;
//            currentmaxprice = prices[i];
//        }
//        else{
//            minprice = prices[i];
//            maxprofit += tmpprofit;
//            tmpprofit = 0;
//            currentmaxprice = minprice;
//        }
//    }
//    maxprofit += tmpprofit;
//    return maxprofit;

    int daysnum = prices.size();
    if (daysnum == 0 || daysnum == 1)
        return 0;
    int minprice = prices[0];
    int tmpprofit = 0;
    int maxprofit = 0;
    int currentmaxprice = minprice;
    for(int i=1; i<daysnum; i++){
        if (currentmaxprice <= prices[i]){
            tmpprofit = (prices[i] - minprice) > tmpprofit ? (prices[i] - minprice) : tmpprofit;
            currentmaxprice = prices[i];
        }
        else{
            minprice = prices[i];
            maxprofit += tmpprofit;
            tmpprofit = 0;
            currentmaxprice = minprice;
        }
    }
    maxprofit += tmpprofit;
    return maxprofit;
}
int main(){
    vector<int> test;
//    test.push_back(1);
//    test.push_back(2);
//    test.push_back(3);
//    test.push_back(-1);
//    test.push_back(4);
//    test.push_back(-15);
//    test.push_back(1);
//    test.push_back(6);
//    test.push_back(-26);
    test.push_back(6);
    test.push_back(1);
    test.push_back(3);
    test.push_back(2);
    test.push_back(4);
    test.push_back(7);
    cout<<maxProfit(test)<<endl;
    return 0;
}
