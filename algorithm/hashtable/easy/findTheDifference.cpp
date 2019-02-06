#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for(int i=0;i<s.size();++i){
            m[s[i]]++;
        }
        for(int i=0;i<t.size();++i){
            if(m[t[i]] > 0)
                m[t[i]]--;
            else
                return t[i];
        }
        return ' ';
    }
};

int main()
{
    Solution s;
    cout << s.findTheDifference("abcd", "abcde") << endl;

    return 0;
}