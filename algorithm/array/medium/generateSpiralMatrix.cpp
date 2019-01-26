#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        if(n <= 0)
            return {};
        vector<vector<int>> ret;
        ret.resize(n);
        for(int i=0;i<n;++i)
            ret[i].resize(n);
        int number = 1;
        for(int i=0;i<(n+1)/2;++i){
            if(n-i-1 == i){
                for(int j=i;j<n-i;++j){
                    ret[i][j] = number++;
                }
            }else if(n-i-1==i){
                for(int j=i;j<n-i;++j){
                    ret[j][n-i-1] = number++;
                }
            }else{
                for(int j=i;j<n-i-1;++j){
                    ret[i][j] = number++;
                    //cout << "p1 " << matrix[i][j] << "\t";
                }
                for(int j=i;j<n-i-1;++j){
                    ret[j][n-i-1] = number++;
                    //cout << "p2 " << matrix[j][n-i-1] << "\t";
                }
                for(int j=i;j<n-i-1;++j){
                    ret[n-i-1][n-j-1] = number++;
                    //cout << "p3 " << matrix[n-i-1][n-j-1] << "\t";
                }
                for(int j=i;j<n-i-1;++j){
                    ret[n-j-1][i] = number++;
                    //cout << "p4 " << matrix[n-j-1][i] << "\t";
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    auto ret = s.generateMatrix(5);
    for(auto &row : ret){
        for(auto &elem : row){
            cout << elem << "\t";
        }
        cout << endl;
    }
    return 0;
}