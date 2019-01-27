#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minimumTotal2(vector<vector<int>> &triangle){
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

    int minimumTotal(vector<vector<int>>& triangle){
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
                if(j < dp[i-1].size() && j-1 >= 0){
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                }else if(j-1 >= 0){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }else{
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
            }
        }
        
        /*
        for(int i=0;i<dp.size();++i){
            for(int j=0;j<dp[i].size();++j){
                cout << dp[i][j] << "\t";
            }
            cout << endl;
        }
        */
        int temp = dp.back()[0];
        for(auto elem : dp.back())
            if(elem < temp)
                temp = elem;
        return temp;
    }
};

int main()
{
    vector<vector<int>> triangle{{3},{1,1},{2,1,1},{3,1,2,2}};
    Solution s;
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}