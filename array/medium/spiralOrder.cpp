#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int> ret;
        if(matrix.empty()) return {};
        int row = matrix.size();
        int list = matrix[0].size();

        int loop = list<=row ? (list+1)/2 : (row+1)/2;

        for(int i=0;i<loop;++i){
            if(row-i-1 == i){
                for(int j=i;j<list-i;++j){
                    ret.push_back(matrix[i][j]);
                }
            }else if(list-i-1==i){
                for(int j=i;j<row-i;++j){
                    ret.push_back(matrix[j][list-i-1]);
                }
            }else{
                for(int j=i;j<list-i-1;++j){
                    ret.push_back(matrix[i][j]);
                    //cout << "p1 " << matrix[i][j] << "\t";
                }
                for(int j=i;j<row-i-1;++j){
                    ret.push_back(matrix[j][list-i-1]);
                    //cout << "p2 " << matrix[j][list-i-1] << "\t";
                }
                for(int j=i;j<list-i-1;++j){
                    ret.push_back(matrix[row-i-1][list-j-1]);
                    //cout << "p3 " << matrix[row-i-1][list-j-1] << "\t";
                }
                for(int j=i;j<row-i-1;++j){
                    ret.push_back(matrix[row-j-1][i]);
                    //cout << "p4 " << matrix[row-j-1][i] << "\t";
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix1{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>> matrix2{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    vector<vector<int>> matrix3{{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};
    auto ret = s.spiralOrder(matrix1);
    for(auto elem : ret){
        cout << elem << "\t";
    }
    cout << endl;
    ret = s.spiralOrder(matrix2);
    for(auto elem : ret){
        cout << elem << "\t";
    }
    cout << endl;
    ret = s.spiralOrder(matrix3);
    for(auto elem : ret){
        cout << elem << "\t";
    }
    cout << endl;
    return 0;
}