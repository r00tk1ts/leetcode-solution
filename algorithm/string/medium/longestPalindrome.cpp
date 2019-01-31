#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution{
public:
    string longestPalindrome_dp(string s) {

        int n = s.size();
        if (n<=1) return s;

        //Construct a matrix, and consdier matrix[j][i] as s[i] -> s[j] is Palindrome or not.
        //                                 ------^^^^^^
        //                                 NOTE: it's [j][i] not [i][j]

        bool **matrix  = (bool**)malloc(n*sizeof(bool*));
        int start=0, len=0;
        // Dynamic Programming
        //   1) if i == j, then matrix[i][j] = true;
        //   2) if i != j, then matrix[i][j] = (s[i]==s[j] && matrix[i-1][j+1])
        for (int i=0; i<n; i++){
            matrix[i] = (bool*)malloc((i+1)*sizeof(bool));
            memset(matrix[i], false, (i+1)*sizeof(bool));
            matrix[i][i]=true;
            for (int j=0; j<=i; j++){
                // The following if statement can be broken to
                //   1) j==i, matrix[i][j] = true
                //   2) the length from j to i is 2 or 3, then, check s[i] == s[j]
                //   3) the length from j to i > 3, then, check s[i]==s[j] && matrix[i-1][j+1]
                if ( i==j || (s[j]==s[i] && (i-j<2 || matrix[i-1][j+1]) ) )  {
                    matrix[i][j] = true;
                    if (len < i-j+1){
                        start = j;
                        len = i-j+1;
                    }
                }
            }
        }

        for (int i=0; i<n; i++) { 
            free (matrix[i]);
        }
        free(matrix);

        return s.substr(start, len);
    }

    string longestPalindrome(string s){
        int n = s.size();
        if (n<=1) 
            return s;

        int start=0, len=0; 

        for (int i=0; i<n-1; i++) {
            findPalindrome(s, i, i, start, len);
            findPalindrome(s, i, i+1, start, len);
        }

        return s.substr(start, len);
    }

    void findPalindrome(string s, int left, int right, int& start, int& len)
    {
        int n = s.size();
        int l = left;
        int r = right;
        while (left>=0 && right<=n-1 && s[left] == s[right]) {
            --left;
            ++right;
        }
        if (right-left-1 > len){
            len = right-left-1;
            start = left+1;
        }
    }

    string longestPalindrome2(string s){
		int start = 0, end = 0;
		int length = s.size();
		
		if (length == 0)
			return "";
		if (length == 1)
			return s;
		
		// guarantee the length is enough to deal
		for (int i = 0; i < length-1; i++){
			int oddLen = longestPalindromeByCenter(s, i, i);
			int evenLen = longestPalindromeByCenter(s, i, i + 1);
			int len = max(oddLen, evenLen);
			if ((end - start) < len){
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}

	int longestPalindromeByCenter(string &s, int i, int j){
		while (i >= 0 && j < s.size() && i <= j && s[i] == s[j])
		{
			i--;
			j++;
		}
		return j - i - 1;
	}
};

int main()
{
    Solution sol;
    cout << sol.longestPalindrome("babbad") << endl;
    return 0;
}

