#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        for(int i=0;i<nums1.size();++i){
            ++m[nums1[i]];
        }
        
        vector<int> v;
        for(int i=0;i<nums2.size();++i){
            if(m[nums2[i]] > 0){
                v.push_back(nums2[i]);
                --m[nums2[i]];
            }
        }
        return v;
    }
};

int main()
{
    Solution s;
    vector<int> v1{1,2,2,1}, v2{2,2};
    auto ret = s.intersect(v1, v2);
    for(auto &elem : ret){
        cout << elem << "\t";
    }
    cout << endl;
    return 0;
}