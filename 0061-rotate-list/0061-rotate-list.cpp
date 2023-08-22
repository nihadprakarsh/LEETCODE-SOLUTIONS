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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        int count=0;
        if(head==NULL)
            return NULL;
        while(temp->next)
        {
            count++;
            temp=temp->next;
        }
        temp->next=head;
        count++;
        int cut=count-k%count;
        temp=head;
        for(int i=1;i<cut;i++)
        {
            temp=temp->next;
        };
        ListNode* ans=temp->next;
        temp->next=NULL;
        return ans;
        
    }
};