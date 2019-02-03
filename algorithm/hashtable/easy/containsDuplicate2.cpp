#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate2(vector<int>& nums, int k) {
        unordered_map<int, vector<size_t>> m;
        for(int i=0;i<nums.size();++i){
            m[nums[i]].push_back(i);
        }
        for(auto iter = m.begin();iter != m.end();++iter){
            for(int i=0;i<iter->second.size()-1;++i){
                if(iter->second[i+1] - iter->second[i] <= k)
                    return true;
            }
        }
        return false;
    }

     bool containsNearbyDuplicate(vector<int>& nums, int k){
        unordered_map<int, size_t> m;
        for(int i=0;i<nums.size();++i){
            if(m.find(nums[i]) != m.end()){
                if(i - m[nums[i]] <= k)
                    return true;
                else
                    m[nums[i]] = i;
            }else{
                m[nums[i]] = i;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> v{1,2,3,1};
    Solution s;
    cout << boolalpha << s.containsNearbyDuplicate(v, 3) << endl;
    return 0;
}