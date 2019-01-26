#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int> &prices){
        int max = 0;
        for(int i=0;i<prices.size();++i){
            for(int j=i+1;j<prices.size();++j){
                if(prices[j]-prices[i] > max)
                    max = prices[j] - prices[i];
            }
        }
        return max;
    }

    int maxProfit2(vector<int> &prices){
        int max = 0;
        int buy = 0;
        for(int i=1;i<prices.size();++i){
            if(prices[i] < prices[buy])
                buy = i;
            if(i != buy && prices[i]-prices[buy] > max)
                max = prices[i] - prices[buy];
        }
        return max;
    }
};

int main()
{
    vector<int> v = {7,6,4,3,1};
    Solution s;
    cout << s.maxProfit2(v) << endl;
    return 0;
}