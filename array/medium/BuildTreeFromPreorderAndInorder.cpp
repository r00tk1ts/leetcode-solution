#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
        unordered_map<int, int> inorder_map;
        for(int i=0;i<inorder.size();++i){
            inorder_map.emplace(inorder[i], i);
        }
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size(), inorder_map);
    }

    TreeNode *helper(vector<int> &preorder, int pre_s, int pre_e, vector<int> &inorder, int in_s, int in_e, unordered_map<int, int> &inorder_map){
        if(pre_s == pre_e || in_s == in_e)
            return nullptr;
        
        int index = inorder_map.at(preorder[pre_s]);
        int left_tree_size = index - in_s;
        TreeNode *node = new TreeNode(preorder[pre_s]);
        node->left = helper(preorder, pre_s+1, pre_s+1+left_tree_size, inorder, in_s, index, inorder_map);
        node->right = helper(preorder, pre_s+1+left_tree_size, pre_e, inorder, index+1, in_e, inorder_map);
        return node;
    }

    void traverse_inorder(TreeNode *root){
        if(root == nullptr)
            return ;
        traverse_inorder(root->left);
        cout << root->val << "\t";
        traverse_inorder(root->right);
    }
};

int main()
{
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);
    s.traverse_inorder(root);
    return 0;
}