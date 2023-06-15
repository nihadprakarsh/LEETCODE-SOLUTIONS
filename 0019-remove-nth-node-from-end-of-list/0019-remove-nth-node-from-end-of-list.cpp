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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
         ListNode* temp = new ListNode();
        temp->next=head;
        ListNode* f=head, *s=head;
        for(int i=1;i<=n;++i)
            f=f->next;
        if(!f) return head->next;
        while(f->next)
        {
            f=f->next;
            s=s->next;
        }
        // cout<<s->val;
        s->next=s->next->next;
        return temp->next;
    }
};