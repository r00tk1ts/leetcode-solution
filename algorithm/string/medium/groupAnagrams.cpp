#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs){
        map<string, multiset<string>> m;
        vector<vector<string>> ret;
        for(int i=0;i<strs.size();++i){
            auto word = strs[i];
            sort(word.begin(), word.end());
            m[word].insert(strs[i]);
        }

        for(auto elem : m){
            vector<string> v(elem.second.begin(), elem.second.end());
            ret.push_back(v);
        }
        //sort(ret.begin(),ret.end(),[](vector<string> v1, vector<string> v2){return v1.size() < v2.size();});
        return ret;
    }

    vector<vector<string>> groupAnagrams2(vector<string> &strs){
        map<string, vector<string>> m;
        vector<vector<string>> ret;
        for(int i=0;i<strs.size();++i){
            auto word = strs[i];
            sort(word.begin(), word.end());
            m[word].push_back(strs[i]);
        }

        for(auto elem : m){
            vector<string> v(elem.second.begin(), elem.second.end());
            ret.push_back(v);
        }
        //sort(ret.begin(),ret.end(),[](vector<string> v1, vector<string> v2){return v1.size() < v2.size();});
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<string> v{"eat","tea","tan","ate","nat","bat"};
    auto ret = sol.groupAnagrams2(v);
    for(auto row : ret){
        for(auto elem : row){
            cout << elem << "\t";
        }
        cout << endl;
    }
    return 0;
}