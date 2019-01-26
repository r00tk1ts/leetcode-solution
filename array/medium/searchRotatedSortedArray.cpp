#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target){
        int begin = 0, end = nums.size()-1;
        while(begin <= end){
            int mid = begin + (end - begin) / 2;
            if(target == nums[mid])
                return mid;
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
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums{4,5,6,7,0,1};
    cout << s.search(nums,4) << "\t"
    << s.search(nums,5) << "\t"
    << s.search(nums,6) << "\t"
    << s.search(nums,7) << "\t"
    << s.search(nums,0) << "\t"
    << s.search(nums,1) << "\t"
    << s.search(nums,2) << "\t"
    << s.search(nums,3) << endl;
    return 0;
}