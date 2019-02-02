#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        for(size_t index = 0;index<s.size();++index){
            auto iter = m.find(s[index]);
            if(iter != m.end()){
                if(iter->second != t[index])
                    return false;
            }else{
                m[s[index]] = t[index];
            }
        }
        
        m.clear();
        for(size_t index=0; index<s.size();++index){
            auto iter = m.find(t[index]);
            if(iter != m.end()){
                if(iter->second != s[index])
                    return false;
            }else{
                m[t[index]] = s[index];
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << boolalpha << s.isIsomorphic("egg", "add");
    return 0;
}