/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool fx = false;
    bool fxfind(ListNode* head, TreeNode* root)
    {
        if(!root) return false;
        if(head->val != root->val) return false;
        if(head->val == root->val && !head->next) return true;
        
        return fxfind(head->next, root->left) || fxfind(head->next, root->right);
    }
    void find(ListNode* head, TreeNode* root)
    {
        if(!root) return;
        if(head->val == root->val) fx = fx or fxfind(head,root);
        find(head,root->left);
        find(head,root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        find(head, root);
        return fx;
    }
};