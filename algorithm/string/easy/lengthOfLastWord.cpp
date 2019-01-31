#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        for(int i=s.size()-1;i>=0;--i){
            if(s[i] == ' '){
                --len;
            }else{
                break;
            }
        }
        auto cnt = 0;
        for(int i=len-1; i>=0; --i){
            if(s[i] == ' '){
                return cnt;
            }
            else
                ++cnt;
        }
        
        return len;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLastWord("a") << endl;
    return 0;
}