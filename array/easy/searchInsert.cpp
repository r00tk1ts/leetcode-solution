#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int searchInsert(vector<int> &nums, int target){
        int b = 0, e = nums.size()-1;
        if(target <= nums[b])
            return b;
        if(target > nums[e])
            return e + 1;
        if(target == nums[e])
            return e;

        int mid = (b + e) / 2;
        while(b < e){
            if(nums[mid] == target)
                break;
            if(nums[mid]<target && target<nums[mid+1])
                break;
            if(target > nums[mid])
                b = mid;
            else
                e = mid;
            mid = (b + e) / 2;
        }
        return target == nums[mid] ? mid : mid + 1;
    }
};

int main()
{
    vector<int> nums = {1,2,5,7};
    Solution s;
    cout << s.searchInsert(nums, 0) << endl;
    cout << s.searchInsert(nums, 3) << endl;
    cout << s.searchInsert(nums, 5) << endl;
    cout << s.searchInsert(nums, 7) << endl;
    return 0;
}