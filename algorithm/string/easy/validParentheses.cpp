#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
	bool isValid(string s){
		if (s.empty())
			return true;
		vector<char> v;
		for (int i = 0; i<s.size(); ++i){
			if (s[i] == ']'){
				if (!v.empty() && v.back() == '[')
					v.resize(v.size() - 1);
				else
					return false;
			}
			else if (s[i] == '}'){
				if (!v.empty() && v.back() == '{')
					v.resize(v.size() - 1);
				else
					return false;
			}
			else if (s[i] == ')'){
				if (!v.empty() && v.back() == '(')
					v.resize(v.size() - 1);
				else
					return false;
			}
			else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				v.emplace_back(s[i]);
		}
		if (v.empty())
			return true;
		else
			return false;
	}
};

int main()
{
	Solution s;
	string str;
	cout << boolalpha;
	while (cin >> str){
		cout << s.isValid(str) << endl;
	}
	return 0;
}