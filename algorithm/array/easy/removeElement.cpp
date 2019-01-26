#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * libstdc++的原型：
   template<typename _ForwardIterator, typename _Predicate>
     _ForwardIterator
     __remove_if(_ForwardIterator __first, _ForwardIterator __last,
                 _Predicate __pred)
     {
       __first = std::__find_if(__first, __last, __pred);
       if (__first == __last)
         return __first;
       _ForwardIterator __result = __first;
       ++__first;
       for (; __first != __last; ++__first)
         if (!__pred(__first))
           {
             *__result = _GLIBCXX_MOVE(*__first);
             ++__result;
           }
       return __result;
  }
 */
class Solution{
public:
    int removeElementOriginal(vector<int> &nums, int val){
        auto iter = remove(nums.begin(), nums.end(), val);
        //auto iter = remove_if(nums.begin(), nums.end(), [val](int elem){ return elem == val;});
        //nums.erase(iter, nums.end());
        return iter-nums.begin();
    }
    void dbgprint(vector<int> &nums){
        for(auto &elem : nums){
            cout << elem << "\t";
        }
        cout << endl;
    }
    int removeElement(vector<int> &nums, int val){
        int i = 0;
        for(int j=0; j<nums.size();++j){
            if(nums[j] != val){
                nums[i] = nums[j];
                ++i;
            }
        }
        
        return i;
    }
};

int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    Solution s;
    cout << s.removeElement(nums, 2) << endl;
    s.dbgprint(nums);
    return 0;
}