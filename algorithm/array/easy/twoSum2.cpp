#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while(left < right){
            if(numbers[left] + numbers[right] == target){
                return {left+1, right+1};
            }else if(numbers[left] + numbers[right] > target){
                --right;
            }else{
                ++left;
            }
        }
        return {};
    }
};

int main()
{
    Solution s;
    vector<int> v{2,7,11,15};
    auto ret = s.twoSum(v, 9);
    for(auto &elem : ret){
        cout << elem << "\t";
    }
    cout << endl;
    return 0;
}