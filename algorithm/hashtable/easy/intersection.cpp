#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> m;
        vector<int> result;
        for(auto &elem : nums1){
            if(find(nums2.begin(),nums2.end(),elem) != nums2.end())
                m.insert(elem);
        }
        for(auto &elem : m){
            result.push_back(elem);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums1{1,2,2,1}, nums2{1,2};
    auto v = s.intersection(nums1, nums2);
    for(auto &elem : v){
        cout << elem << "\t";
    }
    cout << endl;
    return 0;
}