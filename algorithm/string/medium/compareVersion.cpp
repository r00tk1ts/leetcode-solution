#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

class Solution{
public:
    int compareVersion(string version1, string version2) {
            vector<int> ver1 = split(version1, '.');
            vector<int> ver2 = split(version2, '.');

            rightTrimZero(ver1);
            rightTrimZero(ver2);

            for (int i=0; i<ver1.size() && i < ver2.size(); i++) {
                if (ver1[i] < ver2[i]){
                    return -1;
                }else if(ver1[i] > ver2[i]){
                    return 1;
                }
            }

            if (ver1.size() > ver2.size()) {
                return 1;
            }else if (ver1.size() < ver2.size()) {
                return -1;
            }

            return 0;

        }
private:
    vector<int> split(const string &s, char delim){
        vector<int> elems;
        split(s, delim, elems);
        return elems;
    }
    vector<int> &split(const string &s, char delim, vector<int> &elems){
        stringstream ss(s);
        string item;

        while(getline(ss, item, delim)){
            elems.push_back(atoi(item.c_str()));
        }
        return elems;
    }

    void rightTrimZero(vector<int> &v){
        while(v.back() == 0)
            v.pop_back();
    }
};

int main()
{
    Solution s;
    string s1;
    string s2;
    while(cin >> s1 >> s2)
        cout << s.compareVersion(s1, s2) << endl;
    return 0;
}