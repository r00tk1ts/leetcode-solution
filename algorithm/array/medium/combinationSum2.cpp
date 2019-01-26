#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#undef DEBUG
class Solution{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target){
        vector<vector<int>> ret;
        sort(candidates.begin(), candidates.end());
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
                if(i != left && candidates[i] == candidates[i-1])
                    continue;
                if(candidates[i] <= target){
                    auto t = temp;
                    t.push_back(candidates[i]);
                    helper(candidates, i+1, right, target-candidates[i], ret, t);
                }
            }
        }
};

int main()
{
    vector<int> nums{10,1,2,7,6,1,5};
    Solution s;
    auto ret = s.combinationSum2(nums, 8);
    for(auto &row : ret){
        for(auto &elem : row){
            cout << elem << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    
    nums = {2,5,2,1,2};
    ret = s.combinationSum2(nums, 5);
    for(auto &row : ret){
        for(auto &elem : row){
            cout << elem << "\t";
        }
        cout << "\n";
    }
    return 0;
}