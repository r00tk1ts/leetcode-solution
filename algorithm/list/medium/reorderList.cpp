#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    void reorderList(ListNode *head){
        if (!head || !head->next) {
            return;
        }

        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *tmp = slow->next;
        slow->next = nullptr;
        slow = tmp;

        mergeList(head, reverseList(slow));
    }

    ListNode *reverseList(ListNode *head){
        ListNode dummy(0);
        dummy.next = head;
        ListNode *tail = head;
        ListNode *curr = head->next;
        while(curr != nullptr){
            tail->next = curr->next;
            auto tmp = dummy.next;
            dummy.next = curr;
            curr->next = tmp;
            curr = tail->next;
        }
        return dummy.next;
    }

    ListNode *mergeList(ListNode *list1, ListNode *list2){
        ListNode dummy(-1);
        ListNode *curr = &dummy;

        while(list1 && list2){
            ListNode *tmp = list1->next;

            curr->next = list1;
            curr = curr->next;
            curr->next = list2;
            curr = curr->next;

            list1 = tmp;
            list2 = list2->next;
        }

        if(list1){
            curr->next = list1;
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
    s.reorderList(head);
    while(head){
        cout << head->val << "\t";
        head = head->next;
    }
    return 0;
}