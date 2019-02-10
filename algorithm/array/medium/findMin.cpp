#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // deal with no rotating case
        if(nums[0] <= nums[nums.size()-1])
            return nums[0];
        
        int begin = 0, end = nums.size()-1;
        while(begin <= end){
            auto mid = begin + (end - begin) / 2;
            if(mid == 0){
                return nums[mid+1];
            }else if(nums[mid] < nums[mid-1]){
                return nums[mid];
            }else if(mid == nums.size()-1 || nums[mid] > nums[mid+1]){
                return nums[mid+1];
            }else if(nums[mid] > nums[0]){
                begin = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        // never fall here
        return -1;
    }
};

int main()
{
    vector<int> nums{2,3,4,5,1};
    Solution s;
    cout << s.findMin(nums) << endl;
    return 0;
}