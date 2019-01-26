#include <iostream>

using namespace std;

class Solution{
public:
    int uniquePaths(int m, int n){
        int total = m + n - 2;
        if(m < 0 || n < 0)
            return 0;
        if(m <= n)
            return helper(m-1, total);
        else
            return helper(n-1, total);
    }

    int helper(int n, int total){
        unsigned long sum = 1;
        for(int i=0;i<n;++i)
            sum *= (total - i);

        for(int i=1;i<=n;++i)
            sum /= i;

        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(3,2) << endl;
    cout << s.uniquePaths(7,3) << endl;
    cout << s.uniquePaths(5,3) << endl;
    cout << s.uniquePaths(1,5) << endl;
    return 0;
}