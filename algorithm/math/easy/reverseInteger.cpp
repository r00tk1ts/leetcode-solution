#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while(x){
            if(ret > INT_MAX/10 || (ret == INT_MAX/10 && ret%10 > 7))
                return 0;
            if(ret < INT_MIN/10 || (ret == INT_MIN/10 && ret%10 < -8))
                return 0;
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.reverse(123) << endl;
    return 0;
}