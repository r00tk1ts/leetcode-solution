#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    ListNode *removeElements(ListNode *head, int val){
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy, *curr = head;
        while(curr != nullptr){
            if(curr->val == val){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    Solution s;
    auto* ret = s.removeElements(head, 6);
    while(ret != nullptr){
        cout << ret->val << "\t";
        ret = ret->next;
    }
    cout << endl;
    return 0;
}