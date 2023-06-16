/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB) return nullptr;
        ListNode* a=headA,*b=headB;
        int cnt1 =0, cnt2 = 0;
        while(a||b){
            if(a)
                a=a->next,cnt1++;
            if(b)
                b=b->next,cnt2++;
        }
        if(cnt1<cnt2){
            for(int i=1;i<=abs(cnt1-cnt2);++i)
                headB=headB->next;
        }
        else if(cnt2<cnt1){
            for(int i=1;i<=abs(cnt1-cnt2);++i)
                headA=headA->next;
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};