#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())
            return {};
        vector<int> v;
        map<char, int> m;
        for(int i=0;i<p.size();++i)
            m[p[i]]++;
        
        map<char, int> tmp;
        for(int i=0;i<=s.size()-p.size();++i){
            for(int j=i; j<i+p.size(); ++j){
                tmp[s[j]]++;
            }
            if(tmp == m){
                v.emplace_back(i);
            }
            tmp.clear();
        }
        return v;
    }
};

int main()
{
    Solution s;
    auto ret = s.findAnagrams("cbaebabacd", "abc");
    for(auto &elem : ret){
        cout << elem << "\t";
    }
    cout << endl;
    return 0;
}