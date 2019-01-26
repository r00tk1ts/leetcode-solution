#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    ListNode *reverseList(ListNode *head){
        ListNode dummy(0);
        dummy.next = head;
        ListNode *tail = head;
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

    ListNode *reverseList2(ListNode *head){
        if(head->next == nullptr){
            return head;
        }
        ListNode *dummy = reverseList2(head->next);
        head->next->next = head;
        head->next = nullptr;
        return dummy;
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
    auto ret = s.reverseList2(head);
    while(ret != nullptr){
        cout << ret->val << "\t";
        ret = ret->next;
    }
    cout << endl;
    return 0;
}