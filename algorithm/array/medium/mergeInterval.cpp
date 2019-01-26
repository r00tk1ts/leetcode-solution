#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval{
    int start;
    int end;
    Interval():start(0),end(0){}
    Interval(int s, int e):start(s),end(e){}
};

class Solution{
public:
    vector<Interval> merge(vector<Interval> &intervals){
        if(intervals.empty())
            return {};
        
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){return a.start < b.start;});
        vector<Interval> ret{intervals[0]}; 
        for(int i=1;i<intervals.size();++i){
            if(intervals[i].start <= ret.back().end && ret.back().end < intervals[i].end){
                ret.back().end = intervals[i].end;
            }else if(intervals[i].start <= ret.back().end && ret.back().end >= intervals[i].end){
                
            }else{
                ret.push_back(intervals[i]);
            }
        }
        
        return ret;
    }
};

int main()
{
    vector<Interval> intervals{{1,3},{2,6},{8,10},{15,18}};
    Solution s;
    auto ret = s.merge(intervals);
    for(auto interval : ret){
        cout << "[" << interval.start << "," << interval.end << "]\n";
    }
    return 0;
}