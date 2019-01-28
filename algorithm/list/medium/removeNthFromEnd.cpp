#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n){
        ListNode *find, *curr;
        ListNode dummy(-1);
        dummy.next = head;
        curr = &dummy;
        if(n <= 0)
            return head;
        while(n > 0 && curr){
            curr = curr->next;
            --n;
        }

        if(curr == nullptr)
            return head;
        else
            find = &dummy;

        while(curr){
            curr = curr->next;
            if(curr == nullptr){
                find->next = find->next->next;
                break;
            }else{
                find = find->next;
            }
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
    Solution s;
    int n;
    cin >> n;
    auto ret = s.removeNthFromEnd(head, n);
    while(ret){
        cout << ret->val << "\t";
        ret = ret->next;
    }
    cout << endl;
    return 0;
}