#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
	string simplifyPath(string path){
		int upDepth = 0;
		string ret;
		for (int i = path.size() - 1; i >= 1; --i){
			if (path[i] == '/' && i == path.size()-1)
				continue;
			if (path[i] == '/' && path[i - 1] == path[i])
				continue;
			if (path[i] == '/' && path[i - 1] == '.')
				continue;
			if (path[i] == '.'){
				if (path[i - 1] == '.'){
					++upDepth;
					i -= 2;
					continue;
				}
				else{
					--i;
					continue;
				}
			}
			if (upDepth){
				--i;
				while (path[i] != '/')
					--i;
				--upDepth;
			}
			else{
				ret += path[i];
			}
		}
		ret += '/';
		reverse(ret.begin(), ret.end());
		if (ret.back() == '/' && ret.size() != 1)
			ret.resize(ret.size() - 1);
		return ret;
	}
};

int main()
{
	Solution s;
	cout << s.simplifyPath("/a/./b/../../c/") << endl;
	return 0;
}