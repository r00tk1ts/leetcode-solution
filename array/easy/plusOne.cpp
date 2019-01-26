#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<int> plusOne(vector<int> &digits){
        vector<int> result;
        int carry = 0;
        for(int i=digits.size()-1;i>=0;--i){
            if(digits[i] == 9 && (carry == 1 || i == (digits.size()-1))){
                result.push_back(0);
                if(i == (digits.size()-1))
                    carry = 1;
            }else{
                if(i == (digits.size()-1) || carry == 1)
                    result.push_back(digits[i]+1);
                else
                    result.push_back(digits[i]);
                carry = 0;
            }
        }
        if(carry == 1)
            result.push_back(1);
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> digits{9,9,9,9};
    auto ret = s.plusOne(digits);
    for(auto elem : ret){
        cout << elem;
    }
    cout << endl;
    return 0;
}