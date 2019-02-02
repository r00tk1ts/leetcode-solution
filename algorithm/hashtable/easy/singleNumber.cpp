#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    // Time complexity: O(n)
    // Space complexity: O(n)
    int singleNumber1(vector<int> &nums){
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();++i){
            ++m[i];
        }
        for(auto iter=m.begin();iter!=m.end();++iter){
            if(iter->second == 1)
                return iter->first;
        }
        return 0;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)
    int singleNumber2(vector<int> &nums){
        int result = 0;
        for(int i=0;i<nums.size();++i)
            result = result ^ nums[i];
        return result;
    }

    
};

int main(){
    Solution s;
    vector<int> v{4,1,2,1,2};
    cout << s.singleNumber2(v) << endl;
    return 0;
}