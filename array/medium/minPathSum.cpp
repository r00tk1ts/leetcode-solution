#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minPathSum(vector<vector<int>> &grid){
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
};

int main()
{
    vector<vector<int>> v{{1,2,3},{4,5,6}};
    vector<vector<int>> v2{{1,3,1,2},{1,5,1,7},{4,2,1,1}};
    Solution s;
    cout << s.minPathSum(v) << endl;
    //cout << s.minPathSum(v2) << endl;
    return 0;
}