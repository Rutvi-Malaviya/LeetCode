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
    
    ListNode * reverse(ListNode *head){
        ListNode *curr, *prev, *next;
        curr = prev = next = NULL;
        
        curr = head;
        next = head->next;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n=0, m=0;
        
        ListNode *t=l1;
        
        while(t){
            n++;
            t = t->next;
        }
        
        t = l2;
        
        while(t){
            m++;
            t = t->next;
        }
        
        ListNode *list1=reverse(l1), *list2 = reverse(l2);
        
        ListNode *ans=NULL;
        
        int carry=0;
        
        int loop = min(m,n);
        
        while(loop--){
            int sum = list1->val + list2->val + carry;
        
            carry = sum/10;
            sum = sum%10;
            
            ListNode *t = new ListNode(sum, ans);
            ans = t;
            
            list1 = list1->next;
            list2 = list2->next;
        }
        
        if(n>m){
            int loop = n-m;
            while(loop--){
                int sum = carry + list1->val;
                
                carry = sum / 10;
                sum = sum % 10;
                
                ListNode *t = new ListNode(sum, ans);
                ans = t;
                list1 = list1->next;
            }
        }
        else{
            int loop = m-n;
            while(loop--){
                int sum = carry + list2->val;
                
                carry = sum / 10;
                sum = sum % 10;
                
                ListNode *t = new ListNode(sum, ans);
                ans = t;
                list2 = list2->next;
            }
        }
        
        if(carry){
            ans = new ListNode(carry, ans);
        }
        
        return ans;
    }
};
