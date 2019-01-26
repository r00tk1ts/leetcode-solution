#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.empty())
            return 0;
        int cnt = 0;
        int left = 0, curr = 0;
        while(curr < nums.size()){
            //cout << left << "\t" << curr << endl;
            if(curr == 0 || nums[curr] == nums[curr-1]){
                if(cnt < 2){
                    nums[left] = nums[curr];
                    ++cnt;
                    ++left, ++curr;
                }else{
                    ++curr;
                }
            }else{
                nums[left] = nums[curr];
                cnt = 1;
                ++left, ++curr;
            }
        }
        nums.erase(nums.begin()+left, nums.end());
        return nums.size();
    }
};

int main(){
    vector<int> nums{1,1,1,2,2,3};
    vector<int> nums2{0,0,1,1,1,1,2,3,3};
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
    for(auto &elem : nums)
        cout << elem << "\t";
    cout << endl;
    cout << s.removeDuplicates(nums2) << endl;
    for(auto &elem : nums2)
        cout << elem << "\t";
    cout << endl;
    return 0;
}