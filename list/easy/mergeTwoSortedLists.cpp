#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode *p1 = l1, *p2 = l2;
        ListNode *ret = new ListNode(0); 
        ListNode *curr = ret;
        while(p1 != nullptr && p2 != nullptr){
            if(p1->val < p2->val){
                curr->next = new ListNode(p1->val);
                p1 = p1->next;
            }else{
                curr->next = new ListNode(p2->val);          
                p2 = p2->next;
            }
            curr = curr->next;
        }
        while(p1 != nullptr){
            curr->next = new ListNode(p1->val);
            p1 = p1->next;
            curr = curr->next;
        }
        while(p2 != nullptr){
            curr->next = new ListNode(p2->val);
            p2 = p2->next;
            curr = curr->next;
        }
        return ret->next;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode *head = s.mergeTwoLists(l1, l2);
    ListNode *curr = head;
    while(curr != nullptr){
        cout << curr->val << "\t";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}