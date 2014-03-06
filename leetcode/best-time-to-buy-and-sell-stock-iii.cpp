#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
    int daysnum = prices.size();
    if (daysnum == 0 || daysnum == 1)
        return 0;
    int minprice = prices[0];
    int maxprofit = 0;
    int *profitforward = new int[daysnum + 5];
    int *profitbackward = new int[daysnum + 5];
    profitforward[0] = 0;
    int i;
    for(i=1; i<daysnum; i++){
        minprice = minprice < prices[i] ? minprice : prices[i];
        maxprofit = (prices[i] - minprice) > maxprofit ? (prices[i] - minprice) : maxprofit;
        profitforward[i] = maxprofit;
    }
    maxprofit = 0;
    profitbackward[daysnum-1] = 0;
    int maxprice = prices[daysnum-1];
    for (i = daysnum - 2; i >= 0; i--) {
        if (prices[i] > maxprice) {
            maxprice = prices[i];
        }
        if ((maxprice - prices[i]) > maxprofit) {
            maxprofit = maxprice - prices[i];
        }
        profitbackward[i] = maxprofit;
    }
    maxprofit = 0;
    for (i = 0; i < daysnum; i++) {
        if ((profitforward[i] + profitbackward[i]) > maxprofit) {
            maxprofit = profitforward[i] + profitbackward[i]; 
        }
    }
    return maxprofit;
}

int main() {
    int a[] = {
        1,2,1,3,2,4,3,1
        };
    int len = sizeof(a)/sizeof(int);
    int i;
    vector<int> prices;
    for (i = 0; i < len; i++) {
        prices.push_back(a[i]);
    }
    cout<<maxProfit(prices)<<endl;
}
