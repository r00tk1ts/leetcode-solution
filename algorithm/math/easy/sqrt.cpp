#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    // linear search
    int mySqrt2(int x) {
        int i;
        if(x == 1)
            return 1;
        for(i=0;i<x/2;++i){
            if(i*i <= x && (INT_MAX/(i+1) < (i+1) || (i+1)*(i+1) > x)){
                break;
            }
        }
        return i;
    }
    
    // binary search
    int mySqrt(int x){
        if (x < 0)
            return INT_MIN;
            
        if (x == 0)
            return 0;
        
        int left = 1, right = x, mid = 0, factor = 0;
        
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            
            factor = x / mid;
            
            if (mid == factor)
                return mid;
            else if (mid < factor)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
    
    // Newton's method
    int mySqrt3(int x) {
        if (x < 0)
            return INT_MIN;
        if (x == 0)
            return 0;
        
        double pre = 0.0, cur = 1.0;
        
        do
        {
            pre = cur;
            cur = (pre + (x / pre)) / 2;
        }while(abs(cur - pre) > 0.0001);
        
        return (int)cur;
    }
};

int main()
{
    Solution s;
    cout << s.mySqrt(100) << endl;
    return 0;
}