#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        if(strs.empty())
            return "";
        int n = strs.size(), len = 0;
        string common = "";
        while(len < strs[0].size()){
            char c = strs[0][len];
            for(int i=1;i<n;++i){
                if(len >= strs[i].size() || strs[i][len] != c)
                    return common;
            }
            ++len;
            common += c;
        }
        return common;
    }
};

int main()
{
    vector<string> v{"flower","flow","flight"};
    Solution s;
    cout << s.longestCommonPrefix(v) << endl;
    return 0;
}