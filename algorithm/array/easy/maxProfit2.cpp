#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int> &prices){
        int max = 0;
        for(int i=1;i<prices.size();++i){
            if(prices[i] > prices[i-1])
                max += prices[i] - prices[i-1];
        }
        return max;
    }

    int maxProfit2(vector<int> &prices){
        int max = 0;
        int valley, peak;
        int i = 0;
        while(i < prices.size()-1){
            while(i < prices.size()-1 &&prices[i] >= prices[i+1])
                ++i;
            valley = prices[i];
            while(i < prices.size()-1 && prices[i] <= prices[i+1])
                ++i;
            peak = prices[i];
            max += peak - valley;
        }
        return max;
    }
};

int main()
{
    vector<int> v = {1,7,2,3,6,7,6,7};
    Solution s;
    cout << s.maxProfit2(v) << endl;
    return 0;
}