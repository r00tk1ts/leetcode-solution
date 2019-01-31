#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<string> restoreIpAddresses(string s){
        vector<string> result;
        dfs(s, 0, 0, "", result);
        return result;
    }

    void dfs(string &s, size_t index, int part, string path, vector<string> &result){
        int len = s.size();
        if(len-index < 4-part || len-index > (4-part)*3){
            return ;
        }

        if(part == 4 && index == len){
            result.push_back(path);
            return ;
        }

        int num = 0;
        for(int i=index;i<index+3;++i){
            num = num*10 + (s[i]-'0');
            if(num <= 255){
                path += s[i];
                dfs(s, i+1, part+1, (part+1 == 4 ? path : path+'.'), result);
            }
            // only 0.0.0.0 is valid, skip others
            if(num == 0){
                break;
            }
        }
    }
};

int main()
{
    Solution s;
    auto ret = s.restoreIpAddresses("25525511135");
    for(auto &elem : ret){
        cout << elem << "\t";
    }
    cout << endl;
    return 0;
}