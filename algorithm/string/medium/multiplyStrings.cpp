#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    string multiply(string num1, string num2){
        if (num1.size()<=0 || num2.size()<=0) return "";

        int shift=0;
        string result="0";
        for (int i=num1.size()-1; i>=0; --i) {
            string s = multiply(num2, num1[i]);        
            for(int j=0; j<shift; j++){
                s.insert(s.end(), '0');
            }
            result = strPlus(result, s);
            ++shift;
        }

        if (result[0]=='0') 
            return "0";
        return result;
    }
private:
    string multiply(string& num, char ch){
        int n = ch - '0';
        string s;
        int carry = 0;
        int x;

        for(int i=num.size()-1; i>=0; --i){
            x = (num[i]-'0') * n + carry;
            carry = x / 10;
            s.insert(s.begin(), x % 10 + '0'); 
        }
        if (carry > 0) {
            s.insert(s.begin(), carry + '0');
        }
        return s;
    }

    string strPlus(string& num1, string& num2) {
        string s;
        int carry=0;
        int sum;
        int n1 = num1.size(); 
        int n2 = num2.size(); 
        
        int i, j;
        for(i=n1-1, j=n2-1; i>=0 || j>=0; --i, --j){
            int x1 = i >= 0 ?  num1[i] - '0' : 0;
            int x2 = j >= 0 ?  num2[j] - '0' : 0;
            sum = x1 + x2 + carry; 
            carry = sum / 10;
            s.insert(s.begin(), sum % 10 + '0');
        }
        if (carry > 0) {
            s.insert(s.begin(), carry + '0');
        }
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.multiply("123","456") << endl;
    return 0;
}

