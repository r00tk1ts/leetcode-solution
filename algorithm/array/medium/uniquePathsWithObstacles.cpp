#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        if(obstacleGrid.empty() || obstacleGrid[0][0] == 1)
            return 0;
        if(obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1){
            return (obstacleGrid[0][0] == 1 ? 0 : 1);
        }
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int ret = 0;
        //helper(obstacleGrid, m-1, n-1, ret);
        ret = helper2(obstacleGrid, m-1, n-1);
        return ret;
    }

    void helper(vector<vector<int>>& obstacleGrid, int right, int down, int &ret){
        if(right == 0 && down == 0){
            ret += 1;
            return;
        }
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(right > 0 && obstacleGrid[n-down-1][m-right] == 0){
            helper(obstacleGrid, right-1, down, ret);
        }
        if(down > 0 && obstacleGrid[n-down][m-right-1] == 0){
            helper(obstacleGrid, right, down-1, ret);
        }
    }

    int helper2(vector<vector<int>>& obstacleGrid, int right, int down){
        if(right == 0 && down == 0)
            return 1;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(right > 0 && obstacleGrid[n-down-1][m-right] == 0 
            && down > 0 && obstacleGrid[n-down][m-right-1] == 0){
            return helper2(obstacleGrid, right-1, down) + helper2(obstacleGrid, right, down-1);
        }else if(down > 0 && obstacleGrid[n-down][m-right-1] == 0){
            return helper2(obstacleGrid, right, down-1);
        }else if(right > 0 && obstacleGrid[n-down-1][m-right] == 0){
            return helper2(obstacleGrid, right-1, down);
        }else{
            return 0;
        }
    }

    int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid){
        if(obstacleGrid.empty() || obstacleGrid[0][0] == 1)
            return 0;
        if(obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1){
            return (obstacleGrid[0][0] == 1 ? 0 : 1);
        }
        // dynamic programming
        // init
        vector<vector<int>> dp(obstacleGrid.size(), {});
        for(int i=0;i<dp.size();++i){
            for(int j=0;j<obstacleGrid[0].size();++j){
                if(obstacleGrid[i][j] == 1){
                    dp[i].push_back(-1);
                }else{
                    dp[i].push_back(0);
                }
            }
        }    
        dp[0][0] = 1;
        for(int i=0;i<dp.size();++i){
            for(int j=0;j<dp[0].size();++j){
                if(dp[i][j] == -1)
                    continue;
                if(i-1>=0 && dp[i-1][j] > 0)
                    dp[i][j] += dp[i-1][j];
                if(j-1>=0 && dp[i][j-1] > 0)
                    dp[i][j] += dp[i][j-1];
            }
        }
        return dp.back().back() == -1 ? 0 : dp.back().back();
    }
};

int main(){
    Solution s;
    vector<vector<int>> obstacleGrid{{0,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}