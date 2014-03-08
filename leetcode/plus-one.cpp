#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits){
	bool carry = false;
	int n = size-1;
	int i;
	digits[n]++;
	if (digits[n] >= 10) {
		digits[n] -= 10;
		carry = true;
	}
	n--;
	while(carry){
		digits[n]++;
		if (digits[n] >= 10) {
			digits[n] -= 10;
			carry = true;
		}
		else {
			carry = false;
		}
		n--;
		if(n<0 && carry) {
			digits[0] = 1;
			digits.push_back(0);
			break;	
		}
	}
	return digits;
}
