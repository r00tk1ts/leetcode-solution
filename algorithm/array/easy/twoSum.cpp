#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();++i){
            if(m.find(target - nums[i]) != m.end())
                return {m[target - nums[i]], i};
            else
                m[nums[i]] = i;// elem with same value will occupy
        }
        return {};
    }
};

int main()
{

    return 0;
}