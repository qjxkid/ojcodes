#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target){
            vector<int> ans;
            int x1,x2;
            int i1,i2;
            int flag = 0;
            vector<int> tmp(numbers);
            sort(tmp.begin(), tmp.end());

            int len = numbers.size();
            int h=0, t=len-1;
            while(h<=t){
                if(tmp[h] + tmp[t] < target){
                    h++;
                }
                else if(tmp[h] + tmp[t] > target){
                    t--;  
                }
                else {
                    x1 = tmp[h];
                    x2 = tmp[t];
                    break;
                }
            }
            // do something.
            for(int i=0;i<len;i++) {
                if(numbers[i] == x1 || numbers[i] == x2){
                    ans.push_back(i+1);
                    if(flag==0)
                        flag++;
                    else
                        break;
                }
            }
            return ans;
        }
             
};
int main(){
    vector<int> n;
    n.push_back(150);
    n.push_back(24);
    n.push_back(79);
    n.push_back(50);
    n.push_back(88);
    n.push_back(345);
    n.push_back(3);
    Solution a;
    vector<int> b;
    b = a.twoSum(n, 200);
    cout<<b[0]<<"\n"<<b[1]<<endl;
}
