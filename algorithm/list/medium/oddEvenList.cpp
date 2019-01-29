#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    ListNode *oddEvenList(ListNode *head){
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;
        ListNode *odd_head = head, *podd = odd_head;
        ListNode *even_head = head->next, *peven = even_head;
        ListNode *curr = head->next->next;
        
        while(curr){
            podd->next = curr;
            podd = podd->next;
            curr = curr->next;

            peven->next = curr;
            peven = peven->next;
            if(curr)
                curr = curr->next;
        }
        podd->next = even_head;
        return odd_head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    //head->next->next->next->next->next = new ListNode(6);
    
    Solution s;
    auto ret = s.oddEvenList(head);
    while(ret){
        cout << ret->val << "\t";
        ret = ret->next;
    }
    return 0;
}