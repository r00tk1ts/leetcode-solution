#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        if(nums.empty())
            return {};
        vector<vector<int>> ret;
        helper(nums, 0, {}, ret);
        return ret;
    }

    void helper(vector<int> &nums, int pos, vector<int> temp, vector<vector<int>> &ret){
        if(pos == nums.size()){
            ret.push_back(temp);
            return;
        }
        
        helper(nums, pos+1, temp, ret);
        temp.push_back(nums[pos]);
        helper(nums, pos+1, temp, ret);
    }
};

int main()
{
    vector<int> nums{1,2,3};
    Solution s;
    auto ret = s.subsets(nums);
    for(const auto &row : ret){
        for(const auto &elem : row){
            cout << elem << "\t";
        }
        cout << endl;
    }
    return 0;
}