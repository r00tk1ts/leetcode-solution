#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        auto length = 0;
        auto curr = root;
        while (curr) {
            curr = curr->next;
            length += 1;
        }
        auto width = length / k;
        auto remainder = length % k;

        vector<ListNode *> result;
        curr = root;
        for (int i = 0; i < k; ++i) {
            auto head = curr;
            for (int j = 0; curr && j < width - 1 + (i < remainder ? 1 : 0); ++j) {
                curr = curr->next;
            }
            if (curr) {
                auto tail = curr;
                curr = curr->next;
                tail->next = nullptr;
            }
            result.emplace_back(head);
        }
        return result;
    }
};

int main()
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    root->next->next->next->next->next = new ListNode(6);
    root->next->next->next->next->next->next = new ListNode(7);
    root->next->next->next->next->next->next->next = new ListNode(8);
    Solution s;
    auto ret = s.splitListToParts(root, 3);
    for(auto head : ret){
        auto tmp = head;
        while(tmp){
            cout << tmp->val << "\t";
            tmp = tmp->next;
        }
        cout << endl;
    }
    return 0;
}