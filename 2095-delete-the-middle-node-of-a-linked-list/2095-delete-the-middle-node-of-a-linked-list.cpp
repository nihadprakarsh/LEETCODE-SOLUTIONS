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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return nullptr;
        ListNode* f=head,*s=head,*prev=nullptr;
        while(f&&f->next){
            f=f->next->next;
            prev=s;
            s=s->next;
        }
        prev->next=s->next;
        return head;
    }
};