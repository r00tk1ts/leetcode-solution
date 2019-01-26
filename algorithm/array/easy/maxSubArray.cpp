#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxSubArray(vector<int> &nums){
        int max = 0, sum = 0;
        int b = 0, e = 0;
        for(int i=0;i<nums.size();++i){
            sum += nums[i];
            if(sum > max)
                max = sum;
            if(sum < 0)
                sum = 0;
        }
        return max;
    }
};

int main()
{
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxSubArray(nums) << endl;
    return 0;
}