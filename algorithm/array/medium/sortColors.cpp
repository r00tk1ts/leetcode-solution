#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void sortColors(vector<int> &nums){
        // two-pass algorithm using counting sort.
        vector<int> cnt{0, 0, 0};
        for(const auto &elem : nums){
            ++cnt[elem];
        }

        int k = 0;
        for(int i=0;i<3;++i){
            for(int j=0;j<cnt[i];++j){
                nums[k++] = i;
            }
        }
    }

    void sortColors2(vector<int> &nums){
        int left = 0, right = nums.size()-1;
        int curr = 0;
        while(curr <= right){
            if(nums[curr] == 1)
                ++curr;
            else if(nums[curr] == 0)
                swap(nums[curr++], nums[left++]);
            else if(nums[curr] == 2)
                swap(nums[curr], nums[right--]);
        }
    }
};

int main()
{
    vector<int> nums{2,0,2,1,1,0,1,2,0,2,1,2,2,0,0,1};
    Solution s;
    s.sortColors2(nums);
    for(const auto &elem : nums){
        cout << elem << "\t";
    }
    cout << "\n";
    
    return 0;
}