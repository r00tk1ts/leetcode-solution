#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target = 0){
        vector<vector<int>> result;
        if(nums.size() < 4)
            return {};
        sort(nums.begin(), nums.end());

        for(int m=0;m<nums.size()-3;++m){
            if(m == 0 || nums[m] != nums[m-1]){
                for(int i=m+1;i<nums.size()-2;++i){
                    if(i == m+1 || nums[i] != nums[i-1]){
                        for(int j=i+1, k=nums.size()-1;j<k;){
                            if(j-1 > i && nums[j] == nums[j-1]){
                                ++j;
                            }else if(k+1 < nums.size() && nums[k] == nums[k+1]){
                                --k;
                            }else{
                                auto sum = nums[m] + nums[i] + nums[j] + nums[k];
                                if(sum > target)
                                    --k;
                                else if(sum < target)
                                    ++j;
                                else
                                    result.push_back({nums[m], nums[i],nums[j++],nums[k--]});
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> v{1,0,-1,-1,0,0,-2,2};
    Solution s;
    auto ret = s.fourSum(v, 0);
    for(auto row : ret){
        cout << "[";
        for(auto elem : row)
            cout << elem << "\t";
        cout << "]" << endl;
    }
    return 0;
}