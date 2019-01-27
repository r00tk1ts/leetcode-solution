#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    bool search(vector<int>& nums, int target){
        int begin = 0, end = nums.size()-1;
        while(begin <= end){
            if(nums[begin] < nums[end] && (target < nums[begin] || target > nums[end]))
                return false;
            
            // skip duplicates
            while(begin < end && nums[begin] == nums[end])
                ++begin;
            
            int mid = (begin + end) / 2;
            if(target == nums[mid])
                return true;
            else if(nums[mid] >= nums[begin]){
                if(target < nums[mid] && target >= nums[begin]){
                    end = mid - 1;
                }else{
                    begin = mid + 1;
                }
            }else{
                if(target <= nums[end] && nums[mid] < target){
                    begin = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums{2,5,6,0,0,1,2,2,2};
    cout << boolalpha << s.search(nums,2) << "\t"
    << s.search(nums,5) << "\t"
    << s.search(nums,6) << "\t"
    << s.search(nums,0) << "\t"
    << s.search(nums,1) << "\t"
    << s.search(nums,2) << "\t"
    << s.search(nums,3) << "\t"
    << s.search(nums,4) << endl;
    return 0;
}