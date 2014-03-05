#include <iostream>
#include <cmath>

using namespace std;

double pow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    double tmp = pow(x, abs(n)/2);
    tmp *= tmp;
    if (n%2)
        tmp *= x;
    if(n > 0) {
        return tmp;
    }
    else {
        return 1.0/tmp;
    }
}


int main() {
    cout << pow(34.00515,-3)<<endl;
}
