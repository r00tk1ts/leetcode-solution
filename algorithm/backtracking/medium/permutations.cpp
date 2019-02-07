#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        helper(nums, {}, ret);
        return ret;
    }

    void helper(vector<int> &nums, vector<int> path, vector<vector<int>> &ret){
        if(nums.size() == path.size()){
            ret.push_back(path);
            return ;
        }
        for(int i=0;i<nums.size();++i){
            if(find(path.begin(), path.end(), nums[i]) == path.end()){
                path.push_back(nums[i]);
                helper(nums, path, ret);
                path.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums{1,2,3};
    auto ret = s.permute(nums);
    for(auto row : ret){
        for(auto elem : row){
            cout << elem << "\t";
        }
        cout << endl;
    }
    return 0;
}