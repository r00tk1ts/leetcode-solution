#include <iostream>
#include <unordered_set>

using namespace std;

class Solution{
public:
    int squares(int n){
        int result = 0;
        for(;n>0;n/=10){
            auto sq = n%10;
            result += sq*sq;
        }
        return result;
    }

    bool isHappy(int n){
        unordered_set<int> m;
        m.insert(n);

        while(n != 1){
            n = squares(n);
            if(m.find(n) != m.end()){
                return false;
            }
            m.insert(n);
        }
        return true;
    }
};

int main()
{
    Solution s;
    int n;
    while(cin >> n)
        cout << boolalpha << s.isHappy(n) << endl;
    return 0;
}