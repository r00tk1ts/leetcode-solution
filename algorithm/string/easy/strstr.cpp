#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    int strStr(string haystack, string needle){
        if(needle.empty())
            return 0;
        
        return KMP(haystack, needle);
    }

    int KMP(string haystack, string needle){
        vector<int> next = getNext(needle);
        int i = 0, j = 0;

        while(i < static_cast<int>(haystack.size()) && j < static_cast<int>(needle.size())){
            if(j == -1 || haystack[i] == needle[j]){
                ++i;
                ++j;
            }else{
                j = next[j];
            }
        }
        if(j == needle.size())
            return i - j;
        else
            return -1;
    }

    vector<int> getNext(string needle){
        vector<int> next(needle.size());
        next[0] = -1;
        int i = 0, j = -1;
        while(i < needle.size()-1){
            if(j == -1 || needle[i] == needle[j]){
                next[++i] = ++j;
            }else{
                j = next[j];
            }
        }
        return next;
    }
};

int main()
{
    Solution s;
    for(string haystack, needle; cin >> haystack >> needle;){
        cout << s.strStr(haystack, needle) << endl;
    }
    return 0;
}