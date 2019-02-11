#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n >= 1){
            res = (char)('A' + (n - 1) % 26) + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int n;
    while(cin >> n)
        cout << s.convertToTitle(n) << endl;
    return 0;
}