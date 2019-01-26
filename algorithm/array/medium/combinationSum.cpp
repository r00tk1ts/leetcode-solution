#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> ret;
        helper(candidates, 0, candidates.size()-1, target, ret, {});
        return ret;
    }
    void helper(vector<int>& candidates, int left, int right, int target, vector<vector<int>>& ret, vector<int> temp){
#ifdef DEBUG
        cout << "target: " << target << endl;
        for(auto &e : temp)
            cout << e << "\t";
        cout << endl;  
#endif
        if(target == 0){
            ret.push_back(temp);
            return;
        }
           
        for(int i=left;i<=right;++i){
            if(candidates[i] <= target){
                auto t = temp;
                t.push_back(candidates[i]);
                helper(candidates, i, right, target-candidates[i], ret, t);
            }
        }
    }
};

int main()
{
    vector<int> nums{2,3,5};
    Solution s;
    auto ret = s.combinationSum(nums, 8);
    for(auto row : ret){
        for(auto elem : row){
            cout << elem << "\t";
        }
        cout << endl;
    }
    return 0;
}