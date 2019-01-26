#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    void rotate(vector<vector<int>> &matrix){
        if(matrix.empty())
            return ;
        int row = matrix.size();
        for(int i=0;i<row/2;++i){
            for(int j=i;j<row-i-1;++j){
                auto temp = matrix[i][j];
                matrix[i][j] = matrix[row-j-1][i];
                matrix[row-j-1][i] = matrix[row-i-1][row-j-1];
                matrix[row-i-1][row-j-1] = matrix[j][row-i-1];
                matrix[j][row-i-1] = temp;
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix2{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution s;
    s.rotate(matrix2);
    for(auto &row : matrix2){
        for(auto &elem : row)
            cout << elem << "\t";
        cout << endl;
    }
    return 0;
}