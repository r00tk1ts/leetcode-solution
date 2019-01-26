#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    bool canJump(vector<int>& nums){
        if(nums.empty())
            return false;
        
        return help(nums, 0);
    }

    bool help(vector<int>& nums, int pos){
        if(pos == nums.size()-1)
            return true;
        int distance = nums[pos]+pos < nums.size()-1 ? nums[pos]+pos : nums.size()-1;
        //cout << "pos:" << pos << " nums[pos]" << nums[pos] << endl;
        for(int i=1+pos;i<=distance;++i){
            if(help(nums, i))
                return true;
        }
        return false;
    }

    // dynamic programming
    bool canJump2(vector<int>& nums){
        if(nums.empty())
            return false;
        if(nums.size() == 1)
            return true;
        if(nums[0] == 0)
            return false;
        
        vector<bool> dp(nums.size(),false);
        dp[0] = true;
        for(int i=1;i<nums.size();++i){
            for(int j=i-1;j>=0;--j){
                if(dp[j] == true && nums[j] >= i-j){
                    dp[i] = true;
                    break;
                }   
            }
        }
        return dp[nums.size()-1];
    }
};

int main()
{
    vector<int> nums1{2,3,1,1,4}, nums2{3,2,1,0,4};
    Solution s;
    cout << s.canJump2(nums1) << endl;
    cout << s.canJump2(nums2) << endl;
    return 0;
}