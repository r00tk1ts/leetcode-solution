#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
	string countAndSay(int n){
		string s1 = "1", s2;
		for (int i = 1; i<n; ++i){
			auto cnt = 1;
			for (int j = 1; j<s1.size(); ++j){
				if (s1[j] == s1[j - 1]){
					++cnt;
				}
				else{
					s2 += cnt + '0';
					s2 += s1[j - 1];
					cnt = 1;
				}
			}
			s2 += cnt + '0';
			s2 += s1.back();
		
			s1 = s2;
			s2 = "";
		}
		cout << s1 << endl;
		return s1;
	}
};

int main()
{
	Solution s;
	s.countAndSay(5);
	return 0;
}