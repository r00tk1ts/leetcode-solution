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
        int left = -1, right = -1, nbegin = 0;
        for(int i=0;i<s.size();++i){
            if(isspace(s[i]))
                continue;
            if(i == 0 || isspace(s[i-1]))
                left = i;
            if(i == s.size()-1 || isspace(s[i+1])){
                right = i;
                reverse(s.begin()+left, s.begin()+right+1);
                if(nbegin < left){
                    for(int j=left; j<=right; ++j){
                        s[nbegin] = s[j];
                        ++nbegin;
                    }
                    if(nbegin < s.size())
                        s[nbegin++] = ' ';
                }else{
                    nbegin = right + 2;
                }
            }
        }
        s = nbegin == 0 ? "" : s.substr(0, nbegin-1);
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