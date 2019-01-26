## Leetcode solution - Array [Easy]

## 1. Two Sum

>Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.
>
>You may assume that each input would have **exactly** one solution, and you may not use the *same*element twice.
>
>**Example:**
>
>```cpp
>Given nums = [2, 7, 11, 15], target = 9,
>
>Because nums[0] + nums[1] = 2 + 7 = 9,
>return [0, 1].
>```

最原始的思路，brute force，O(n^2)的时间复杂度，这个就不说了。

我看到这题的第一反应就是sort+双指针移动。因为题目给定的nums并非是排好序的，所以要先排序，时间复杂度是O(nlgn)，此后定义双指针分别指向头和尾，双向夹逼直至两元素和为target。

很快就发现了问题，这个题目要求返回的是元素的索引而非元素本身，因此，排序之后索引就丢了。为了patch这一思路，在sort之前，考虑先用map存储每个元素的索引，这里还要注意元素可能重复的问题。

第一阶段我写出了这样的代码：

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<size_t>> index;
        for(size_t i=0;i<nums.size();++i)
            index[nums[i]].push_back(i);
        
        sort(nums.begin(), nums.end());
        size_t len = nums.size() - 1;
        size_t cur = 0;
        while(cur != len){
            int temp = nums[cur] + nums[len];
            if(temp == target){
                if(nums[cur] == nums[len])
                    return {index[nums[cur]][0], index[nums[len]][1]};
                else
                    return {index[nums[cur]][0], index[nums[len]][0]};
            }
            else if(temp < target)
                ++cur;
            else
                --len;
        }
        return {};
    }
};
```

可以说是缝缝补补，毫无美感。此时时间复杂度是O(nlgn)，空间复杂度是O(n)。

空间复杂度因为map的问题没办法降至O(1)，进而就想到，既然空间复杂度到了O(n)，又何必去费时排序呢？

把思路转换一下，既然无序，就先把nums的元素和索引存储到一个map中，然后再从头至尾对每个“nums[i]”，都判断一下map是否包含“target-nums[i]”不就行了？

进一步，这个过程可以一次遍历完成，边存储边判断“target-当前元素”的值是否已经在map中，时间复杂度O(n)搞定。

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();++i){
            if(m.find(target - nums[i]) != m.end())
                return {m[target - nums[i]], i};
            else
                m[nums[i]] = i;// elem with same value will occupy
        }
        return {};
    }
};
```

改用了unordered_map，这货底层是哈希表，优化了runtime。

## 26. Remove Duplicates from Sorted Array

>Given a sorted array *nums*, remove the duplicates [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) such that each element appear only *once*and return the new length.
>
>Do not allocate extra space for another array, you must do this by **modifying the input array in-place**with O(1) extra memory.
>
>**Example 1:**
>
>```
>Given nums = [1,1,2],
>
>Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
>
>It doesn't matter what you leave beyond the returned length.
>```
>
>**Example 2:**
>
>```
>Given nums = [0,0,1,1,1,2,2,3,3,4],
>
>Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
>
>It doesn't matter what values are set beyond the returned length.
>```
>
>**Clarification:**
>
>Confused why the returned value is an integer but your answer is an array?
>
>Note that the input array is passed in by **reference**, which means modification to the input array will be known to the caller as well.
>
>Internally you can think of this:
>
>```
>// nums is passed in by reference. (i.e., without making a copy)
>int len = removeDuplicates(nums);
>
>// any modification to nums in your function would be known by the caller.
>// using the length returned by your function, it prints the first len elements.
>for (int i = 0; i < len; i++) {
>    print(nums[i]);
>}
>```

用C++会立马想到unique：

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = unique(nums.begin(), nums.end());
        return it - nums.begin();
    }
};
```

拿来主义确实无耻，但这样就没意思了，至少我们要弄清楚unique的实现。unique是否满足O(1)的空间复杂度呢？可以探索一下标准库unique的实现。

```cpp
template<typename _ForwardIterator, typename _BinaryPredicate>
     _ForwardIterator
     __unique(_ForwardIterator __first, _ForwardIterator __last,
              _BinaryPredicate __binary_pred)
     {
       // Skip the beginning, if already unique.
       __first = std::__adjacent_find(__first, __last, __binary_pred);
       if (__first == __last)
         return __last;
 
       // Do the real copy work.
       _ForwardIterator __dest = __first;
       ++__first;
       while (++__first != __last)
         if (!__binary_pred(__dest, __first))
           *++__dest = _GLIBCXX_MOVE(*__first);
       return ++__dest;
     }
```

确实是in-place，libstdc++的unique确实符合函数的语义描述：

```
template<typename _ForwardIterator >
_ForwardIterator std::unique	(	_ForwardIterator 	__first,
_ForwardIterator 	__last 
)		
inline
Remove consecutive duplicate values from a sequence.

Parameters
__first	A forward iterator.
__last	A forward iterator.
Returns
An iterator designating the end of the resulting sequence.
Removes all but the first element from each group of consecutive values that compare equal. unique() is stable, so the relative order of elements that are not removed is unchanged. Elements between the end of the resulting sequence and __last are still present, but their value is unspecified.
```

unique不能改变容器的size，它在处理之后，返回的迭代器和容器的尾后迭代器之前的元素都是不确定的，因为unique并没有把前面的重复元素挪过去，也确实没有这个必要。

透过unique，这道题的思路其实也就跃然纸上了。

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = 0;
        if(nums.empty())
            return 0;
        
        for(int curr=1; curr<nums.size(); ++curr){
            if(nums[prev] != nums[curr])
                nums[++prev] = nums[curr];
        }
        return prev + 1;
    }
};
```

