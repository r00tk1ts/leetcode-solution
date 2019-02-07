#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    void utils(bitset<32>& bits, vector<int>& result, int k){
        if (k == 0) {
            result.push_back(bits.to_ulong());
        }
        else {
            utils(bits, result, k-1);
            bits.flip(k-1);
            utils(bits, result, k-1);
        }
    }

    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> result;
        utils(bits, result, n);
        return result;
    }
};

int main()
{
    Solution s;
    auto ret = s.grayCode(10);
    for(auto &elem : ret){
        cout << elem << "\t";
    }
    cout << endl;
    return 0;
}