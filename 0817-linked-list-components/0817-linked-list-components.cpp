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
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
     set<int> st;
        for(auto it : nums)
            st.insert(it);
        int ans= 0, c = 0;
        while(head)
        {
            if(st.count(head->val))
                c++;
            else
            {
                if(c)
                    ans+=1;
                c=0;
            }
            head=head->next;
        }
        if(c)
            ans+=1;
        return ans;
    }
};