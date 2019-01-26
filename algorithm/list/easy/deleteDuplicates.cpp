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
        if(head == nullptr)
            return head;
        int temp = head->val;
        ListNode *curr = head->next, *prev = head;
        while(curr != nullptr){
            if(curr->val == temp){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }else{
                temp = curr->val;
                prev = curr;
                curr = curr->next;
            }
            
        }
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    Solution s;
    auto h = s.deleteDuplicates(head);
    while(h != nullptr){
        cout << h->val << "\t";
        h = h->next;
    }
    return 0;
}