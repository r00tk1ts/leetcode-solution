#include <iostream>

using namespace std;

class Node{
public:
	int val;
	Node *prev;
	Node *next;
	Node *child;

	Node() : val(-1), prev(nullptr), next(nullptr), child(nullptr) { }

	Node(int _val, Node *_prev, Node *_next, Node *_child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};

class Solution{
public:
	Node *flatten(Node *head){
		Node *node = head;
		Node dummy, *pd = &dummy;
		dummy.next = &dummy;
		dummy.prev = &dummy;

		while (node){
			if (node->child == nullptr){
				pd->next = new Node(node->val, node->prev, node->next, node->child);
				pd->next->prev = pd;
				pd = pd->next;
			}
			else{
				pd->next = new Node(node->val, node->prev, node->next, node->child);
				pd->next->child = nullptr;
				pd = pd->next;
				pd->next = flatten(node->child);
				pd->next->prev = pd;
				auto tail = pd->next;
				while (tail->next){
					tail = tail->next;
				}
				pd = tail;
			}
			node = node->next;
		}
		dummy.next->prev = nullptr;
		return dummy.next;
	}
};

int main()
{
	Node l11, l12, l13, l14, l15, l16, l21, l22, l23, l24, l31, l32;
	l11.val = 1, l11.next = &l12;
	l12.val = 2, l12.prev = &l11, l12.next = &l13;
	l13.val = 3, l13.prev = &l12, l13.next = &l14, l13.child = &l21;
	l14.val = 4, l14.prev = &l13, l14.next = &l15;
	l15.val = 5, l15.prev = &l14, l15.next = &l16;
	l16.val = 6, l16.prev = &l15;

	l21.val = 7, l21.next = &l22;
	l22.val = 8, l22.prev = &l21, l22.next = &l23, l22.child = &l31;
	l23.val = 9, l23.prev = &l22, l23.next = &l24;
	l24.val = 10, l24.prev = &l23;

	l31.val = 11, l31.next = &l32;
	l32.val = 12, l32.prev = &l31;

	Solution s;
	auto ret = s.flatten(&l11);
	while (ret){
		cout << ret->val << "\t";
		ret = ret->next;
	}
	cout << endl;
	return 0;
}