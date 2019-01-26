#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int mininumTotal(vector<vector<int>> &triangle){
        if(triangle.empty())
            return 0;
        return helper(triangle, 0, 0, 0);
    }

    int helper(vector<vector<int>> &triangle, int depth, int index, int sum){
        if(depth == triangle.size())
            return sum;
        
        int left = helper(triangle, depth+1, index, sum+triangle[depth][index]);
        int right = depth != 0 ? helper(triangle, depth+1, index+1, sum+triangle[depth][index+1]) : -1;
        
        return right == -1 ? left : left < right ? left : right;
    }
};

int main()
{
    vector<vector<int>> triangle{{3},{1,1},{2,1,1},{3,1,2,2}};
    Solution s;
    cout << s.mininumTotal(triangle) << endl;
    return 0;
}