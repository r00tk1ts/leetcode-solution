#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <bitset>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> m;
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(m.find(board[i][j]) != m.end())
                    return false;
                else if(board[i][j] != '.')
                    m.insert(board[i][j]);   
            }
            m.clear();
        }
        
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(m.find(board[j][i]) != m.end())
                    return false;
                else if(board[j][i] != '.')
                    m.insert(board[j][i]);
            }
            m.clear();
        }
        

        for(int k=0;k<3;++k){
            for(int n=0;n<3;++n){
                for(int i=0;i<3;++i){
                    for(int j=0;j<3;++j){
                        if(m.find(board[i+k*3][j+n*3]) != m.end())
                            return false;
                        else if(board[i+k*3][j+n*3] != '.')
                            m.insert(board[i+k*3][j+n*3]);
                    }
                }
                m.clear();
            }
        }
        
        return true;
    }

    bool isValidSudoku2(vector<vector<char>>& board) {
        array<bitset<9>, 9> row, col;
        array<array<bitset<9>, 3>, 3> box;
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0' - 1;
                    if (row[i].test(n) || col[j].test(n) || box[i / 3][j / 3].test(n)) {
                        return false;
                    }
                    row[i].set(n), col[j].set(n), box[i / 3][j / 3].set(n);
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    
    vector<vector<char>> v{{'5','3','.','.','7','.','.','.','.'}, {'6','.','.','1','9','5','.','.','.'}, {'.','9','8','.','.','.','.','6','.'}, 
                            {'8','.','.','.','6','.','.','.','3'}, {'4','.','.','8','.','3','.','.','1'}, {'7','.','.','.','2','.','.','.','6'},
                            {'.','6','.','.','.','.','2','8','.'}, {'.','.','.','4','1','9','.','.','5'}, {'.','.','.','.','8','.','.','7','9'}
                        };
    /*
    vector<vector<char>> v{{'.','.','.','.','5','.','.','1','.'}, {'.','4','.','3','.','.','.','.','.'}, {'.','.','.','.','.','3','.','.','1'},
                            {'8','.','.','.','.','.','.','2','.'}, {'.','.','2','.','7','.','.','.','.'}, {'.','1','5','.','.','.','.','.','.'},
                            {'.','.','.','.','.','2','.','.','.'}, {'.','2','.','9','.','.','.','.','.'}, {'.','.','4','.','.','.','.','.','.'}
                        };
    */
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << boolalpha << s.isValidSudoku2(v) << endl;
    return 0;
}