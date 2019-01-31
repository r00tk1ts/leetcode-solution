#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int numDecodings(string s){
        if(s[0] == '0')
            return 0;
		return helper(s);
	}

	int helper(string s){
		if(s[0] == '0')
			return 0;
		if (s.size() <= 1){
            return 1;
        }
		
		int number = atoi(s.substr(0, 2).c_str());
		if (1 <= number && number <= 26){
			return helper(s.substr(1)) + helper(s.substr(2));
		}
		else{
			return helper(s.substr(1));
		}
	}
};

int main()
{
	Solution s;
	cout << s.numDecodings("101") << endl;
	return 0;
}