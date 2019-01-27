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
    TreeNode *buildTree(vector<int> &postorder, vector<int> &inorder){
        unordered_map<int, int> inorder_map;
        for(int i=0;i<inorder.size();++i){
            inorder_map.emplace(inorder[i], i);
        }
        return helper(postorder, postorder.size()-1, -1, inorder, 0, inorder.size(), inorder_map);
    }

    TreeNode *helper(vector<int> &postorder, int post_s, int post_e, vector<int> &inorder, int in_s, int in_e, unordered_map<int, int> &inorder_map){
        if(post_s == post_e || in_s == in_e)
            return nullptr;
        
        int index = inorder_map.at(postorder[post_s]);
        int right_tree_size = post_s - post_e - index + in_s - 1;
        TreeNode *node = new TreeNode(postorder[post_s]);
        node->left = helper(postorder, post_s-right_tree_size-1, post_e, inorder, in_s, index, inorder_map);
        node->right = helper(postorder, post_s-1, post_s-right_tree_size-1, inorder, index+1, in_e, inorder_map);
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
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    Solution s;
    TreeNode *root = s.buildTree(postorder, inorder);
    s.traverse_inorder(root);
    return 0;
}