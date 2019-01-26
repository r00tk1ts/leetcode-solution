#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

class Solution{
public:
    bool exist(vector<vector<char>> &board, string word){
        if(word.empty() || board.empty())
            return false;
        char c = word[0];
        set<pair<int, int>> path;
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j] == c){
                    path.clear();
                    path.insert(make_pair(i,j));
                    //cout << "init " << i << "\t" << j << endl;
                    if(helper(board, word, 1, i, j, path) == true)
                        return true;
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>> &board, string &word, int depth, int xpos, int ypos, set<pair<int,int>> &path){
        if(depth == word.size())
            return true;
        
        char c = word[depth];
        if(xpos - 1 >= 0 && board[xpos-1][ypos] == c){
            if(path.find(make_pair(xpos-1,ypos)) == path.end()){
                path.insert(make_pair(xpos-1, ypos));
                if(helper(board, word, depth+1, xpos-1, ypos, path))
                    return true;
                else
                    path.erase(make_pair(xpos-1, ypos));
            }
        }
        if(xpos + 1 < board.size() && board[xpos+1][ypos] == c){
            if(path.find(make_pair(xpos+1,ypos)) == path.end()){
                path.insert(make_pair(xpos+1,ypos));
                if(helper(board, word, depth+1, xpos+1, ypos, path))
                    return true;
                else
                    path.erase(make_pair(xpos+1,ypos));
            }
        }
        if(ypos - 1 >= 0 && board[xpos][ypos-1] == c){
            if(path.find(make_pair(xpos,ypos-1)) == path.end()){
                path.insert(make_pair(xpos, ypos-1));
                if(helper(board, word, depth+1, xpos, ypos-1, path))
                    return true;
                else
                    path.erase(make_pair(xpos, ypos-1));
            }
        }
        if(ypos + 1 < board[0].size() && board[xpos][ypos+1] == c){
            if(path.find(make_pair(xpos,ypos+1)) == path.end()){
                path.insert(make_pair(xpos, ypos+1));
                if(helper(board, word, depth+1, xpos, ypos+1, path))
                    return true;
                else
                    path.erase(make_pair(xpos, ypos+1));
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    Solution s;
    string temp;
    while(cin >> temp)
        cout << boolalpha << s.exist(board, temp) << endl;
    return 0;
}