#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate2(vector<int>& nums) {
        unordered_set<int> m;
        for(size_t i=0;i<nums.size();++i){
            if(m.find(nums[i]) != m.end())
                return true;
            m.insert(nums[i]);
        }
        return false;
    }

    bool containsDuplicate(vector<int>& nums){
        sort(nums.begin(), nums.end());
        for(size_t i=1;i<nums.size();++i){
            if(nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> v{1,2,3,1};
    cout << boolalpha << s.containsDuplicate(v);
    return 0;
}