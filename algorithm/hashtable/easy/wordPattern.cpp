#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string>c2s;
        unordered_map<string, char>s2c;
        stringstream ss(str);
        string s = "";
        int i = 0;
        while(ss >> s){
            if(i == pattern.size() || (c2s.count(pattern[i]) && c2s[pattern[i]] != s) 
                || (s2c.count(s) && s2c[s] != pattern[i]))
                return false;
            c2s[pattern[i]] = s;
            s2c[s] = pattern[i++];
        }
        return i == pattern.size();
    }
};

int main()
{
    Solution s;
    cout << boolalpha << s.wordPattern("abba", "dog dog dog dog") << endl;
    return 0;
}