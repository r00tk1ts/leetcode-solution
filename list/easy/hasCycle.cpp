#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    bool hasCycle(ListNode *head){
        ListNode *p1 = head, *p2 = head;
        while(p1 != nullptr){
            p1 = p1->next;
            if(p1 != nullptr)
                p1 = p1->next;
            else
                return false;
            p2 = p2->next;
            if(p1 == p2)
                return true;
        }
        return false;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;
    Solution s;
    cout << boolalpha << s.hasCycle(head) << endl;
    return 0;
}