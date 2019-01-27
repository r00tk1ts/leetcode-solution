#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minPathSum2(vector<vector<int>> &grid){
        if(grid.empty())
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        int sum = -1;
        helper(grid, m-1, n-1, 0, sum);
        return sum;
    }

    void helper(vector<vector<int>> &grid, int right, int down, int temp, int& sum){
        //cout << right << "\t" << down << "\t" << temp <<endl;
        if(right == 0 && down == 0){
            if(sum == -1 || temp + grid[grid.size()-1][grid[0].size()-1] < sum){
                sum = temp + grid[grid.size()-1][grid[0].size()-1];
            }
            return;
        }

        int n = grid.size();
        int m = grid[0].size();
        if(right > 0){
            //cout << "1st " << grid[n-down-1][m-right-1] << endl;
            helper(grid, right-1, down, temp+grid[n-down-1][m-right-1], sum);
        }
        if(down > 0){
            //cout << "2nd " << grid[n-down-1][m-right-1] << endl;
            helper(grid, right, down-1, temp+grid[n-down-1][m-right-1], sum);
        }
    }

    // dynamic programming
    int minPathSum(vector<vector<int>>& triangle){
        if(triangle.empty())
            return 0;
        vector<vector<int>> dp(triangle.size());
        for(int i=0;i<dp.size();++i){
            for(int j=0;j<=i;++j){
                dp[i].push_back(0);
            }
        }
        
        dp[0][0] = triangle[0][0];
        for(int i=1;i<dp.size();++i){
            for(int j=0;j<dp[i].size();++j){
                if(j-1 >= 0 && j < dp[i-1].size()){
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                }else{
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
            }
        }
        
        for(int i=0;i<dp.size();++i){
            for(int j=0;j<dp[i].size();++j){
                cout << dp[i][j] << "\t";
            }
            cout << endl;
        }
        
        int temp = dp.back()[0];
        for(auto elem : dp.back())
            if(elem < temp)
                temp = elem;
        return temp;
    }
};

int main()
{
    vector<vector<int>> v{{1,2,5},{3,2,1}};
    vector<vector<int>> v2{{1,3,1,2},{1,5,1,7},{4,2,1,1}};
    Solution s;
    cout << s.minPathSum(v) << endl;
    //cout << s.minPathSum(v2) << endl;
    return 0;
}