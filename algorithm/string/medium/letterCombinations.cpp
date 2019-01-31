#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
	
	vector<string> letterCombinations(string digits){
		if(digits.empty())
            return {};
		vector<string> ret;
		string path;
		dfs(digits, 0, path, ret);
		return ret;
	}

private:
	void dfs(string &digits, int index, string &path, vector<string> &ans){
		vector<string> keyboard = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		if (index == digits.size()){
			ans.push_back(path);
			return;
		}

		for (char c : keyboard[digits[index] - '0']){
			path += c;
			dfs(digits, index + 1, path, ans);
			path.pop_back();
		}
	}
};

int main()
{
	string s = "23";
	Solution sol;
	vector<string> v = sol.letterCombinations(s);
	for (string str : v){
		cout << str << endl;
	}
	return 0;
}