#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n){
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = nullptr, *curr = &dummy;
        int pass = m;
        while(pass > 0){
            --pass;
            prev = curr;
            curr = curr->next;
        }
        prev->next = reverseList(curr, n-m);
        return dummy.next;
    }

    ListNode *reverseList(ListNode *head, int count){
        ListNode dummy(0);
        dummy.next = head;
        ListNode *tail = head;
        ListNode *curr = head->next;
        int cnt = 0;
        while(curr != nullptr && cnt < count){
            tail->next = curr->next;
            auto tmp = dummy.next;
            dummy.next = curr;
            curr->next = tmp;
            curr = tail->next;
            ++cnt;
        }
        ListNode *t = dummy.next;

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
    Solution s;
    auto ret = s.reverseBetween(head,2,4);
    while(ret){
        cout << ret->val << "\t";
        ret = ret->next;
    }
    return 0;
}