#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    // this method needs unique ListNode in LinkedList 
    ListNode *detectCycle2(ListNode *head){
        ListNode *p1 = head, *p2 = head;
        while(p1 != p2 || p1 == head){
            //cout << p1->val << "\t" << p2->val << endl;
            p1 = p1->next;
            p2 = p2->next;
            if(p2->next)
                p2 = p2->next;
            else
                break;
        }
        if(p1 != p2)
            return nullptr;
        
        unordered_set<int> existSet;
        p2 = p2->next;
        while(p1 != p2){
            existSet.emplace(p2->val);
            p2 = p2->next;
        }
        int pos = 0;
        p1 = head;
        while(p1){
            if(existSet.find(p1->val) != existSet.end())
                return p1;
            else
                p1 = p1->next;
        }
        return nullptr;
    }

    ListNode *detectCycle(ListNode *head){
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *p1 = head, *p2 = head->next;
        while(p1 != p2){
            //cout << p1->val << "\t" << p2->val << endl;
            p1 = p1->next;
            p2 = p2->next;
            if(p2 && p2->next)
                p2 = p2->next;
            else
                break;
        }
        if(p1 != p2)
            return nullptr;
        // counting elements in circle
        int len = 1;
        p2 = p2->next;
        while(p1 != p2){
            p2 = p2->next;
            ++len;
        }
        
        p2 = head;
        while(p2){
            for(int i=0;i<len;++i){
                if(p2 == p1)
                    return p2;
                p1 = p1->next;
            }
            p2 = p2->next;
        }
        return nullptr;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = head;
    /*new ListNode(0);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;*/
    Solution s;
    auto ret = s.detectCycle(head);
    cout << ret->val << endl;
    return 0;
}