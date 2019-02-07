#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // dynamic programming
    int climbStairs2(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    
    // optimistic space using
    int climbStairs(int n){
        if(n <= 2) 
            return n;
        
        int n1 = 1, n2 = 2, tmp = 0;
        int i = 3;
        while (i <= n)
        {
            tmp = n1 + n2;
            n1 = n2;
            n2 = tmp;
            ++i;
        }
        
        return n2;
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(10) << endl;
    return 0;
}