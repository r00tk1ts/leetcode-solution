#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    void reverseWords(string &s){
        if(s.empty())
            return ;
        reverse(s.begin(), s.end());
        size_t left = 0, right = 0;
        while(right < s.size()){
            if(s[right] != ' '){
                ++right;
            }else{
                reverse(s.begin()+left, s.begin()+right);
                ++right;
                left = right;
            }
        }
        reverse(s.begin()+left, s.end());
        size_t begin = 0, end = s.size()-1;
        for(int i=0;i<s.size();++i){
            if(s[i] == ' '){
                ++begin;
            }else{
                break;
            }
        }
        for(int i=s.size()-1;i>=0;--i){
            if(s[i] == ' '){
                --end;
            }else{
                break;
            }
        }
        s = s.substr(begin, end-begin+1);
    }
};

int main()
{
    Solution sol;
    string str = "the sky is blue";
    sol.reverseWords(str);
    cout << str << endl;
    return 0;
}