#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // deal with empty case
        if(nums.empty()){
            return -1;
        }
        if(nums.size() == 1)
            return 0;
        if(nums[0] > nums[1])
            return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2])
            return nums.size()-1;
        
        for(int i=1;i<nums.size()-1;++i){
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1])
                return i;
        }
        // nonexist
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> v{1,2,3,1};
    cout << s.findPeakElement(v) << endl;
    return 0;
}