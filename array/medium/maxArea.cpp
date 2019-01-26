#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int maxArea(vector<int> &height){
        auto b = height.begin(), e = height.end()-1;
        int max = 0;
        while(b != e){
            if(min(*b, *e) * (e - b) > max)
                max = min(*b, *e) * (e - b);
            if(*b < *e)
                ++b;
            else
                --e;
        }
        return max;
    }
};

int main()
{
    vector<int> nums{1,8,6,2,5,4,8,3,7};
    Solution s;
    cout << s.maxArea(nums) << endl;
}