#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
        int i = 0, j = 0;
        vector<int> temp;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j])
                temp.push_back(nums1[i++]);
            else
                temp.push_back(nums2[j++]);
        }
        if(i < m){
            for(int k = i; k < m; ++k)
                temp.push_back(nums1[k]);
        }
        if(j < n){
            for(int k = j; k < n; ++k)
                temp.push_back(nums2[k]);
        }

        nums1 = temp;
    }
};

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    Solution s;
    s.merge(nums1, 3, nums2, 3);
    for(auto e : nums1)
        cout << e << "\t";
    cout << endl;
    return 0;
}