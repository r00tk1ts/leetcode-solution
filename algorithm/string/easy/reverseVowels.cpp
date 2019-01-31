#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    string reverseVowels(string s){
        if(s.empty())
            return s;
        size_t left = 0, right = s.size()-1;
        while(left < right){
            if(isVowels(s[left]) == false){
                ++left;
                continue;
            }
            if(isVowels(s[right]) == false){
                --right;
                continue;
            }
            auto tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            ++left;
            --right;
        }
        return s;
    }

    bool isVowels(char c){
        c |= 0x20;
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        else
            return false;
    }
};

int main()
{
    Solution sol;
    cout << sol.reverseVowels("leetcode") << endl;
    cout << sol.reverseVowels("hello") << endl;
    return 0;
}