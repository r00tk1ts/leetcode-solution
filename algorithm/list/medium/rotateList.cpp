#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    ListNode *rotateRight(ListNode *head, int k){
        int len = 0;
        ListNode *curr = head;
        if(head == nullptr)
            return head;
        while(curr != nullptr){
            ++len;
            curr = curr->next;
        }
        k = k % len;
        if(k == 0)
            return head;
            
        ListNode dummy(-1), *d = &dummy;
        dummy.next = head;
        ListNode *p1 = d, *p2 = d;
        while(k > 0){
            p1 = p1->next;
            --k;
        }
        while(p1->next != nullptr){
            p1 = p1->next;
            p2 = p2->next;
        }
        auto temp = dummy.next;
        dummy.next = p2->next;
        p2->next = nullptr;
        p1->next = temp;

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
    int n;
    cin >> n;
    ListNode *ret = s.rotateRight(head, n);
    while(ret){
        cout << ret->val << "\t";
        ret = ret->next;
    }
    cout << endl;
    
    return 0;
}