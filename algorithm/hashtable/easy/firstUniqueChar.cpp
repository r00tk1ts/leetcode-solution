#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for(int i=0;i<s.size();++i){
            ++m[s[i]];
        }
        for(int i=0;i<s.size();++i){
            if(m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.firstUniqChar("leetcode") << endl;
    return 0;
}