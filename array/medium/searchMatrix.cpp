#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target){
        if(matrix.empty() || matrix[0].empty())
            return false;
        int n = matrix.size();
        int m = matrix[0].size();
        
        int start = 0, end = n-1;
        int area = -1;
        while(start <= end){
            auto mid = start + (end - start)/2;
            if( matrix[mid][0] <= target && target <= matrix[mid][m-1]){
                area = mid;
                break;
            }else if(matrix[mid][0] > target)
                end = mid - 1;
            else
                start = mid + 1;
            
        }
        if(area == -1)
            area = n - 1;
        start = 0, end = m-1;
        while(start <= end){
            auto mid = start + (end - start) / 2;
            if(matrix[area][mid] == target)
                return true;
            else if(matrix[area][mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        
        return false;
    }
};

int main()
{
    vector<vector<int>> v{{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    Solution s;
    int element;
    while(cin >> element)
        cout << boolalpha << s.searchMatrix(v,element) << endl;
    return 0;
}