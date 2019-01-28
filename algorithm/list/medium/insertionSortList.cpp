#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
	ListNode *insertionSortList(ListNode *head){
		if (!head || !head->next)
			return head;
		ListNode *curr = head->next;
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *tail = nullptr;
		while (curr){
			ListNode *prev = dummy.next, *pprev = &dummy;
			while (prev != curr){
				if (tail == nullptr)
					tail = prev;
				if (prev->val > curr->val){
					auto tmp = curr->next;
					pprev->next = curr;
					tail->next = curr->next;
					curr->next = prev;
					curr = tmp;
					break;
				}
				else{
					pprev = prev;
					prev = prev->next;
					if (tail->next != curr)
						tail = tail->next;
				}
			}
			if (prev == curr)
				curr = curr->next;
		}
		return dummy.next;
	}


};

int main()
{
	ListNode *head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(0);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(1);
	Solution s;
	auto ret = s.insertionSortList(head);
	while (ret){
		cout << ret->val << "\t";
		ret = ret->next;
	}
	cout << endl;
	return 0;
}