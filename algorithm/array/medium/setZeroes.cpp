#include <iostream>
#include <vector>

#undef DEBUG

using namespace std;

class Solution{
public:
    void setZeroes(vector<vector<int>> &matrix){
        if(matrix.empty())
            return;
        
        int m = matrix[0].size();
        int n = matrix.size();
        bool *bitmap = new bool[m+n]{false};
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j] == 0)
                    bitmap[i] = true;
            }
        }
        for(int j=0;j<m;++j){
            for(int i=0;i<n;++i){
                if(matrix[i][j] == 0)
                    bitmap[n+j] = true;
            }
        }
#ifdef DEBUG
        for(int i=0;i<m+n;++i)
            cout << bitmap[i] << "\t";
        cout << endl;
#endif
        for(int i=0;i<m+n;++i){
            if(bitmap[i] == true){
                if(i < n){
                    for(int j=0;j<m;++j)
                        matrix[i][j] = 0;
                }else{
                    for(int j=0;j<n;++j)
                        matrix[j][i-n] = 0; 
                }
            }
        }
        delete[] bitmap;
    }

    void setZeroes2(vector<vector<int>> &matrix){
        if(matrix.empty())
            return;
        int n = matrix.size();
        int m = matrix[0].size();
        bool isCol = false;
        
        for(int i=0;i<n;++i){
            if(matrix[i][0] == 0){
                isCol = true;
            }

            for(int j=1;j<m;++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int j=0;j<m;++j){
                matrix[0][j] = 0;
            }
        }

        if(isCol){
            for(int i=0;i<n;++i){
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution s;
    s.setZeroes2(matrix);
    for(auto &row : matrix){
        for(auto &elem : row)
            cout << elem << "\t";
        cout << "\n";
    }
    return 0;
}