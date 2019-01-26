#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target){
        int min_diff = numeric_limits<int>::max();
        int result = min_diff;
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
                        if(sum > target){
                            if(sum - target < min_diff){
                                min_diff = sum - target;
                                result = sum;
                            }
                            --k;
                        }else if(sum < target){
                            if(target - sum < min_diff){
                                min_diff = target - sum;
                                result = sum;
                            }
                            ++j;
                        }else
                            return target;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> v{-1,2,1,-4};
    Solution s;
    auto ret = s.threeSumClosest(v, 1);
    cout << ret << endl;
    return 0;
}