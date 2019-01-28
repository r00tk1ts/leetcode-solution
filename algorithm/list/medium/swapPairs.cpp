#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    ListNode *swapPairs(ListNode *head){
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *left = head;
        ListNode *right = head->next;
        ListNode dummy(-1), *prev = &dummy;
        dummy.next = head;
        while(left && right){
            left->next = right->next;
            right->next = left;
            prev->next = right;

            right = left->next;
            if(right) 
                right = right->next;
            prev = left;
            left = left->next;
        }
        return dummy.next;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    
    Solution s;
    auto ret = s.swapPairs(head);
    while(ret){
        cout << ret->val << "\t";
        ret = ret->next;
    }
    return 0;
}