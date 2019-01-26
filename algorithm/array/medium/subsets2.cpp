#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        if(nums.empty())
            return {};
        vector<vector<int>> ret;
        helper(nums, 0, {}, ret);
    /*
        auto iter = unique(ret.begin(),ret.end());
        ret.erase(iter, ret.end());
    */
        return ret;
    }

    void helper(vector<int> &nums, int pos, vector<int> temp, vector<vector<int>> &ret){
        if(pos == nums.size()){
            ret.push_back(temp);
            return;
        }

        if(pos == 0 || nums[pos] != nums[pos-1]){
            helper(nums, pos+1, temp, ret);
        }else if(nums[pos] == nums[pos-1] && (temp.empty() || temp.back() != nums[pos])){
            helper(nums, pos+1, temp, ret);
        }
        temp.push_back(nums[pos]);
        helper(nums, pos+1, temp, ret);
    }
};

int main()
{
    vector<int> nums{1,2,2};
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