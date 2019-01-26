#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> result;
        if(numRows == 0)
            return {};
        result.push_back({1});
        for(int i=1;i<numRows;++i){
            vector<int> temp;
            for(int j=0;j<i+1;++j){
                if(j == 0 || j == i)
                    temp.push_back(1);
                else
                    temp.push_back(result[i-1][j-1]+result[i-1][j]);
            }
            result.push_back(temp);
            temp.resize(0);
        }
        return result;
    }
};

int main()
{
    Solution s;
    auto v = s.generate(10);
    for(auto row : v){
        for(auto elem : row)
            cout << elem << "\t";
        cout << endl;
    }
    return 0;
}