#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
		l1 = reverseList(l1);
		l2 = reverseList(l2);

		ListNode *p1 = l1, *p2 = l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        int len1 = 0, len2 = 0;
        while(p1){
            ++len1;
            p1 = p1->next;
        }

        while(p2){
            ++len2;
            p2 = p2->next;
        }

        p1 = l1;
        p2 = l2;

        int carry = 0;
        for(int i=0;i<(len1 <= len2 ? len1 : len2);++i){
            auto n = p1->val + p2->val + carry;
            if(n >= 10){
                n = n - 10;
                carry = 1;
            }else{
                carry = 0;
            }
            head->next = new ListNode(n);
            head = head->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1){
            auto n = p1->val + carry;
            if(n == 10)
                head->next = new ListNode(0);
            else
                head->next = new ListNode(p1->val+carry);
            if(carry == 1 && n != 10)
                carry = 0;
            p1 = p1->next;
            head = head->next;
        }
        while(p2){
            auto n = p2->val + carry;
            if(n == 10)
                head->next = new ListNode(0);
            else
                head->next = new ListNode(p2->val+carry);
            if(carry == 1 && n != 10)
                carry = 0;
            head = head->next;
            p2 = p2->next;
        }
        if(carry == 1)
            head->next = new ListNode(1);

        return reverseList(dummy->next);
	}

	ListNode *reverseList(ListNode *head){
        ListNode dummy(0);
        dummy.next = head;
        ListNode *tail = head;
        if(tail == nullptr)
            return head;
        ListNode *curr = head->next;
        while(curr != nullptr){
            tail->next = curr->next;
            auto tmp = dummy.next;
            dummy.next = curr;
            curr->next = tmp;
            curr = tail->next;
        }
        return dummy.next;
    }
};

int main()
{
	ListNode *l1 = new ListNode(8);
	l1->next = new ListNode(9);
	l1->next->next = new ListNode(9);
	//l1->next->next->next = new ListNode(3);

	ListNode *l2 = new ListNode(2);
	//l2->next = new ListNode(6);
	//l2->next->next = new ListNode(4);

	Solution s;
	auto ret = s.addTwoNumbers(l1, l2);
	while (ret){
		cout << ret->val << "\t";
		ret = ret->next;
	}
	cout << endl;
	return 0;
}