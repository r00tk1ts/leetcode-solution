#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    void nextPermutation(vector<int>& nums){
        if(nums.size() <= 1)
            return ;
        int target = nums.size() - 1;
        while(--target >= 0){
            if(nums[target] < nums[target+1]){
                break;
            }
        }

        if(target == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        int search = target;
        while(++search < nums.size()){
            if(nums[search] <= nums[target]){
                break;
            }
        }
        --search;
        swap(nums[target], nums[search]);
        reverse(nums.begin()+target+1, nums.end());
    }
};

int main()
{
    vector<int> nums{1,2,5,4,2,2,1};
    Solution s;
    s.nextPermutation(nums);
    for(auto e : nums)
        cout << e << "\t";
    cout << endl;
    return 0;
}