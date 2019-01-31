#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution{
public:
	int lengthOfLongestSubstring(string s){
		int sum = 0;
		int left = -1, right = 0;
		map<char, int> reserve;
		while (right < s.size()){
			if (reserve.find(s[right]) != reserve.end() && left < reserve[s[right]]){
				left = reserve[s[right]];
			}
			if (right - left > sum){
				sum = right - left;
			}
			reserve[s[right]] = right;
			++right;
		}
		return sum;
	}
};

int main()
{
	Solution sol;
	cout << sol.lengthOfLongestSubstring("pwwwkew") << endl;
	return 0;
}