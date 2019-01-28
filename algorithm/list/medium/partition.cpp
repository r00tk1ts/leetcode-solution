#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    ListNode *partition(ListNode *head, int x){
        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode *curr = nullptr;
        for(ListNode *p = &dummy; p && p->next; ){
            if(!curr && p->next->val >= x){
                curr = p;
            }else if(curr && p->next->val < x){
                ListNode *tmp = p->next;
                p->next = tmp->next;
                tmp->next = curr->next;
                curr->next = tmp;
                curr = tmp;
                continue;
            }
            p = p->next;
        }
        return dummy.next;
    }
};

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);

    Solution s;
    auto ret = s.partition(head, 3);
    while(ret){
        cout << ret->val << "\t";
        ret = ret->next;
    }
    return 0;
}