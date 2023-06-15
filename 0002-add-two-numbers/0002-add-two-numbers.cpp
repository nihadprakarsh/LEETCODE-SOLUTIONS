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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* head = new ListNode(); dummy->next = head;
        int carry = 0;
        while(l1 || l2 || carry)
        {
            int sum1 = 0, sum2 = 0;
            if(l1)
            {
                sum1+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum2+=l2->val;
                l2=l2->next;
            }
            int n = (sum1+sum2+carry)%10;
            carry = (sum1+sum2+carry)/10;
            head->next=new ListNode(n);
            head=head->next;
        }
        
        return dummy->next->next;
    }
};