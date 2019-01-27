#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    bool isPalindrome(ListNode *head){
        auto middle = findMiddle(head);
        auto p1 = head;
        auto p2 = reverseList(middle);
        while(p1 && p2){
            if(p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }

    ListNode *findMiddle(ListNode *head){
        ListNode *p1 = head, *p2 = head;
        while(p2 && p2->next){
            p1 = p1->next;
            p2 = p2->next;
            p2 = p2->next;
        }
        return p1;
    }

    ListNode *reverseList(ListNode *head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *dummy = reverseList(head->next);
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
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(1);
    Solution s;
    cout << boolalpha << s.isPalindrome(head) << endl;
    return 0;
}