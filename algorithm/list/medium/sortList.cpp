#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
	ListNode* sortList(ListNode *head){
		if(!head)
			return nullptr;
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *tail = head;
		while (tail->next)
			tail = tail->next;
		quicksort(&dummy, tail);
		return dummy.next;
	}

	void quicksort(ListNode *head, ListNode *tail){
		ListNode *data_head = head->next;
		if (head == tail || data_head == tail)
			return;

		ListNode *left = head, *right = head;
		while (right->next != tail){
			if (right->next->val <= tail->val){
				if (left == right){
					left = left->next;
					right = right->next;
					continue;
				}
				auto post_left = left->next;
				auto post_right = right->next;
				auto temp = post_right->next;
				left->next = post_right;
				post_right->next = post_left;
				right->next = temp;
				left = left->next;
			}
			else{
				right = right->next;
			}
		}
		if (left->next != right->next){
			auto target = right->next;
			auto tmp = left->next;
			right->next = right->next->next;
			left->next = target;
			target->next = tmp;

			quicksort(head, left);
			quicksort(target, right);
		}
		else{
			quicksort(head, left);
		}
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
	auto ret = s.sortList(head);
	while (ret){
		cout << ret->val << "\t";
		ret = ret->next;
	}
	cout << endl;
	return 0;
}