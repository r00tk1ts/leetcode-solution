#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
	string addBinary(string a, string b){
		vector<char> ret;
		int i = a.size() - 1, j = b.size() - 1;
		auto carry = 0;
		while (i >= 0 && j >= 0){
			auto tmp = a[i] - '0' + b[j] - '0' + carry;
			if (tmp >= 2){
				tmp -= 2;
				carry = 1;
			}
			else{
				carry = 0;
			}
			ret.emplace_back(tmp + '0');
			--i;
			--j;
		}
		while (i >= 0){
			auto tmp = a[i] + carry - '0';
			if (tmp >= 2){
				tmp -= 2;
				carry = 1;
			}
			else{
				carry = 0;
			}
			ret.emplace_back(tmp + '0');
			--i;
		}
		while (j >= 0){
			auto tmp = b[j] + carry - '0';
			if (tmp >= 2){
				tmp -= 2;
				carry = 1;
			}
			else{
				carry = 0;
			}
			ret.emplace_back(tmp + '0');
			--j;
		}
		if (carry == 1)
			ret.emplace_back('1');
		return string(ret.rbegin(), ret.rend());
	}
};

int main()
{
	Solution s;
	cout << s.addBinary("11", "1") << endl;
	return 0;
}