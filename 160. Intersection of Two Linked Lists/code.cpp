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
        int la=0, lb=0;
        
        ListNode *temp;
        
        temp = headA;
        
        while(temp){
            la++;
            temp = temp->next;
        }
        
        temp = headB;
        
        while(temp){
            lb++;
            temp = temp->next;
        }
        
        if(la>lb){
            for(int i=0; i<la-lb; i++) headA=headA->next;
        }
        else{
            for(int i=0; i<lb-la; i++) headB=headB->next;
        }
        
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};
