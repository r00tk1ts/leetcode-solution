#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    TreeNode *sortedListToBST(ListNode *head){
        if(head == nullptr)
            return nullptr;
        ListNode dummy(-1);
        dummy.next = head;
        int len = 0;
        ListNode *tail = head, *prev_mid = nullptr, *mid = &dummy;
        while(tail){
            ++len;
            tail = tail->next;
        }

        int pos = (len+1)/2;

        while(pos > 0){
            prev_mid = mid;
            mid = mid->next;
            --pos;
        }

        //cout << prev_mid->val << "  " << mid->val << endl;
        TreeNode *root = new TreeNode(mid->val);
        prev_mid->next = nullptr;
        root->left = sortedListToBST(dummy.next);
        root->right = sortedListToBST(mid->next);

        return root;
    }

    void tranverse(TreeNode *root){
        if(root == nullptr)
            return ;
        tranverse(root->left);
        cout << root->val << "\t";
        tranverse(root->right);
    }
};

int main()
{
    ListNode *head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    Solution s;
    TreeNode *root = s.sortedListToBST(head);
    s.tranverse(root);
    return 0;
}