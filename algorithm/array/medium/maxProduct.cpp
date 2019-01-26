#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int maxProduct(vector<int> &nums){
        if(nums.empty())
            return 0;
        int maxProduct = nums[0];
        int maxPrev, minPrev, maxCurr, minCurr;
        maxPrev = minPrev = maxCurr = minCurr = nums[0];
        for(int i=1;i<nums.size();++i){
            maxCurr = max(max(maxPrev * nums[i], minPrev * nums[i]), nums[i]);
            minCurr = min(min(maxPrev * nums[i], minPrev * nums[i]), nums[i]);
            //cout << maxCurr << "\t" << minCurr << endl;
            maxProduct = max(maxCurr, maxProduct);
            maxPrev = maxCurr;
            minPrev = minCurr;
        }
        return maxProduct;
    }
};

int main()
{
    vector<int> nums{2,3,-2,4};
    Solution s;
    cout << s.maxProduct(nums) << endl;
    return 0;
}