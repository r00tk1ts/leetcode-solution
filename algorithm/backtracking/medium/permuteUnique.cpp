#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void recursion(vector<int> num, int pos, vector<vector<int>> &res) {
        if (pos == num.size()-1) {
            res.push_back(num);
            return;
        }
        for (int k = pos; k < num.size(); k++) {
            if (pos != k && num[pos] == num[k]) 
                continue;
            swap(num[pos], num[k]);
            recursion(num, pos+1, res);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        recursion(num, 0, res);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1,1,2};
    auto ret = s.permuteUnique(nums);
    for(auto &row : ret){
        for(auto &elem : row){
            cout << elem << "\t";
        }
        cout << endl;
    }
    return 0;
}