#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        long long t = n;
        if (t < 0){
            t *= -1;
            x = 1 / x;
        }
        
        while (t > 0){
            if (t & 1) ret *= x;
            x = x * x;
            t >>= 1;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.myPow(2.00000,10);
    return 0;
}