#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> getRow(int rowIndex){
        vector<int> result;
        if(rowIndex <=0)
            return {1};
        for(int i=0;i<rowIndex+1;++i){
            result.insert(result.cbegin(), 1);
            for(int j=1;j<result.size()-1;++j){
                result[j] = result[j] + result[j+1];
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    auto v = s.getRow(10);
    for(auto elem : v)
        cout << elem << "\t";
    cout << endl;
    return 0;
}