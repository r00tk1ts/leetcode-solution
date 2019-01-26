#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        int lenA = 0, lenB = 0;
        ListNode *pA = headA, *pB = headB;
        while(pA != nullptr){
            lenA++;
            pA = pA->next;
        }
        while(pB != nullptr){
            lenB++;
            pB = pB->next;
        }
        if(lenA <= lenB){
            auto diff = lenB - lenA;
            for(int i=0;i<diff;++i){
                headB = headB->next;
            }
        }else{
            auto diff = lenA - lenB;
            for(int i=0;i<diff;++i){
                headA = headA->next;
            }
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};

int main()
{
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;
    Solution s;
    ListNode *ret = s.getIntersectionNode(headA, headB);
    if(ret == nullptr)
        cout << "nullptr" << endl;
    else
        cout << ret->val << endl;
    return 0;
}