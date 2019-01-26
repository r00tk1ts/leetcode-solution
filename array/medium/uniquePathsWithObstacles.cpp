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
};

int main(){
    Solution s;
    vector<vector<int>> obstacleGrid{{0,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}