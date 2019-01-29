#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    int romanCharToInt(char ch){
        int d = 0;
        switch(ch){
        case 'I':  
            d = 1;  
            break;  
        case 'V':  
            d = 5;  
            break;  
        case 'X':  
            d = 10;  
            break;  
        case 'L':  
            d = 50;  
            break;  
        case 'C':  
            d = 100;  
            break;  
        case 'D':  
            d = 500;  
            break;  
        case 'M':  
            d = 1000;  
            break;  
        }
        return d;
}

    int romanToInt(string s) {
        if (s.size()<=0) return 0;
        int result = romanCharToInt(s[0]);
        for (int i=1; i<s.size(); i++){
            int prev = romanCharToInt(s[i-1]);
            int curr = romanCharToInt(s[i]);
            //if left<right such as : IV(4), XL(40), IX(9) ...
            if (prev < curr) {
                result = result - prev + (curr - prev);
            }else{
                result += curr;
            }
        }
        return result;
    }

};

int main()
{
    string str("MCMXCIV");
    Solution s;
    cout << s.romanToInt(str) << endl;
    return 0;
}