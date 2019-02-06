#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for(int i=0;i<s.size();++i){
            m[s[i]]++;
        }
        int ret = 0;
        bool odd = false;
        for(auto &elem : m){
            if(elem.second % 2 == 1){
                ret += elem.second - 1;
                odd = true;
            }else{
                ret += elem.second;
            }
        }
        
        return ret + (odd == true ? 1 : 0);
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("abccccdd") << endl;
    return 0;
}