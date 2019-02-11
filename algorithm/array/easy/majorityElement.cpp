#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        sort(nums.begin(), nums.end());
        return nums[(nums.size())/2];
        */
        return helper(nums, 0, nums.size()-1);
    }
    
    int countInRange(vector<int> &nums, int num, int low, int high){
        int cnt = 0;
        for(int i=low;i<=high;++i){
            if(nums[i] == num){
                cnt++;
            }
        }
        return cnt;
    }
    
    int helper(vector<int> &nums, int low, int high){
        if(low == high)
            return nums[low];
        
        int mid = (high-low)/2+low;
        int left = helper(nums, low, mid);
        int right = helper(nums, mid+1, high);
        
        if(left == right){
            return left;
        }
        
        int leftCnt = countInRange(nums, left, low, high);
        int rightCnt = countInRange(nums, right, low, high);
        
        return leftCnt > rightCnt ? left: right;
    }
};

int main()
{
    Solution s;
    vector<int> v{2,3,3,3,2};
    cout << s.majorityElement(v);
    return 0;
}