#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    bool isPalindrome(string s){
        int left = 0, right = s.size()-1;
        while(left < right){
            if(!isalnum(s[left])){
                ++left;
                continue;
            }
            if(!isalnum(s[right])){
                --right;
                continue;
            }
            if((s[left] | 0x20) != (s[right] | 0x20)){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

int main()
{
    Solution s;
    //cout << boolalpha << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    //cout << s.isPalindrome("race a car") << endl;
    cout << s.isPalindrome("0P") << endl;
    return 0;
}