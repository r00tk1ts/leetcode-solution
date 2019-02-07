#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        helper(1, n, {}, k, res);
        return res;
    }
    
    void helper(int begin, int end, vector<int> path, int k, 
                vector<vector<int>> &res)     
    {
        if(path.size() == k){
            res.push_back(path);
            return ;
        }
        
        for(int i=begin;i<=end;++i){
            path.push_back(i);
            helper(i+1, end, path, k, res);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    auto ret = s.combine(10, 3);
    for(auto &row : ret){
        for(auto &elem : row){
            cout << elem << "\t";
        }
        cout << endl;
    }
    return 0;
}