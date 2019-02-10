#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        stringstream ss, ss2;
        //convert numerator and denominator to long long to avoid overflow
        long long n = numerator, d = denominator ,q = n / d, r = n % d; 
        //add '-' when q == 0 but the whole answer is negative
        if (q == 0 && ((n > 0 && d < 0) || (n < 0 && d > 0)))
            ss << '-';
        ss << q;
        if (r)
            ss << ".";
        unordered_map<long long,int> m;
        int i = 0;
        if (r < 0 ) r = -r;
        if (d < 0 ) d = -d;
        while (r) {
            n = r * 10; //the new numerator
            if (m.find(n) == m.end()) { // haven't seen the new numerator
                q = n / d, r = n % d;
                ss2 << q;
                m[n] = i++; //store the position it occurs
            } else { //see this numerator again, so it must be the beginning of new recurring
                //return integer part, fractional part before recurring and recurring part
                return ss.str() + ss2.str().substr(0,m[n]) + '(' + ss2.str().substr(m[n])+ ')';
            }
        }
        return ss.str() + ss2.str(); //it's non-recurring!
    }
};

int main()
{
    Solution s;
    int n, d;
    while(cin >> n >> d)
        cout << s.fractionToDecimal(n, d) << endl;
    return 0;
}