#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        auto p = head;
        int len = 0;
        while(p){
            ++len;
            p = p->next;
        }
        len /= 2;
        ListNode *middle = head;
        while(len > 0){
            middle = middle->next;
            --len;
        }
        return middle;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution s;
    auto middle = s.middleNode(head);
    cout << middle->val << endl;
    return 0;
}