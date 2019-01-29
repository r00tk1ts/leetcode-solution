#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
	int numComponents(ListNode *head, vector<int>& G){
		
	}
};

int main()
{
	ListNode *head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(4);
	vector<int> G{0,1,2,3,4};

	Solution s;
	cout << s.numComponents(head, G) << endl;
	return 0;
}