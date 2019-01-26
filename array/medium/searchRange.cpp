#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<int> searchRange(vector<int> &nums, int target){
        if(nums.empty())
            return {-1,-1};
        const int begin = lower_bound(nums, target);
        const int end = upper_bound(nums, target);
    
        if (begin < nums.size() && nums[begin] == target) {
            return {begin, end - 1};
        }
        return {-1, -1};
    }

    int upper_bound(vector<int> &nums, int target){
        int left = 0, right = nums.size();
        int mid;
        // Find min left s.t. A[left] > target.
        while(left < right){
            mid = left + (right-left)/2;
            if(nums[mid] > target){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }

    int lower_bound(vector<int> &nums, int target){
        int left = 0, right = nums.size();
        int mid;
        // Find min left s.t. A[left] >= target.
        while(left < right){
            mid = left + (right-left)/2;
            if(nums[mid] >= target){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};

int main()
{
    vector<int> nums{5,7,7,8,8,10};
    Solution s;
    auto r = s.searchRange(nums, 7);
    cout << r[0] << "\t" << r[1] << endl;
     r = s.searchRange(nums, 8);
    cout << r[0] << "\t" << r[1] << endl;
     r = s.searchRange(nums, 5);
    cout << r[0] << "\t" << r[1] << endl;
     r = s.searchRange(nums, 10);
    cout << r[0] << "\t" << r[1] << endl;
     r = s.searchRange(nums, 3);
    cout << r[0] << "\t" << r[1] << endl;
    return 0;
}