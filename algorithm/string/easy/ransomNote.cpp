#include <iostream>
#include <string>
#include <unordered_map> 

using namespace std;

class Solution{
public:
	bool canConstruct(string ransomNote, string magazine){
		unordered_map<char, size_t> map;
		for (auto &elem : magazine){
			++map[elem];
		}
		for (auto &elem : ransomNote){
			if (map.find(elem) != map.end() && map[elem] >= 1){
				--map[elem];
			}
			else{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution sol;
	cout << boolalpha << sol.canConstruct("aa", "aab") << endl;
	cout << sol.canConstruct("aa", "ab") << endl;
	return 0;
}