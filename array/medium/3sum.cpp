#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums, int target = 0){
        vector<vector<int>> result;
        if(nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size()-2;++i){
            if(i == 0 || nums[i] != nums[i-1]){
                for(int j=i+1, k=nums.size()-1;j<k;){
                    if(j-1 > i && nums[j] == nums[j-1]){
                        ++j;
                    }else if(k+1 < nums.size() && nums[k] == nums[k+1]){
                        --k;
                    }else{
                        auto sum = nums[i] + nums[j] + nums[k];
                        if(sum > target)
                            --k;
                        else if(sum < target)
                            ++j;
                        else
                            result.push_back({nums[i],nums[j++],nums[k--]});
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> v{-1,0,1,2,-1,-4};
    Solution s;
    auto ret = s.threeSum(v, 0);
    for(auto row : ret){
        cout << "[";
        for(auto elem : row)
            cout << elem << "\t";
        cout << "]" << endl;
    }
    return 0;
}