#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    ListNode *deleteDuplicates(ListNode *head){
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode dummy(-1), *prev_left = &dummy;
        dummy.next = head;
        ListNode *left = head, *right = head->next;
        bool dup = false;
        while(right != nullptr){
            if(right->val == left->val){
                dup = true;
                left->next = right->next;
                right = right->next;
            }else{
                if(dup == true){
                    prev_left->next = right;
                    left = right;
                    right = right->next;  
                }else{
                    prev_left = left;
                    left = right;
                    right = right->next;
                }
                dup = false;
            }
        }
        if(dup == true){
            prev_left->next = nullptr;
        }
        return dummy.next;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    
    Solution s;
    auto ret = s.deleteDuplicates(head);
    while(ret){
        cout << ret->val << "\t";
        ret = ret->next;
    }

    return 0;
}