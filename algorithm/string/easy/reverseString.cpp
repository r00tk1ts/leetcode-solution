#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void reverseString(vector<char> &s){
        if(s.empty())
            return;
        size_t left = 0, right = s.size()-1;
        while(left < right){
            auto tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            ++left;
            --right;
        }
    }
};

int main()
{
    Solution sol;
    vector<char> s{'h','e','l','l','o'};
    sol.reverseString(s);
    for(auto elem : s){
        cout << elem;
    }
    cout << endl;
    return 0;
}