#include <iostream>

using namespace std;

class Solution{
public:
    int divide(int dividend, int divisor){ 
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
			return INT_MAX;
		}
		int sign = (dividend ^ divisor) >= 0 ? 1 : -1;
		long long newdividend = labs(dividend);
		long long newdivisor = labs(divisor);
		long long ans = 0;
		while (newdividend >= newdivisor) {
			long long tmp = newdivisor;
			int m = 1;
			while (newdividend >= (tmp << 1)) {
				m = m << 1;
				tmp = tmp << 1;
			}
			newdividend -= tmp;
			ans += m;
		}
		return ans * sign;
    }
};

int main()
{
    Solution s;

    for(int dividend, divisor; cin >> dividend >> divisor; )
        cout << s.divide(dividend, divisor) << endl;
    return 0;
}