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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        
        ListNode *ans = NULL, *end=NULL;
        
        ListNode *temp=lists[0];
        int ind = 0;
        
        vector<int> v;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]==NULL){
                v.insert(v.begin(),i);
            }
        }
        
        for(int i: v){
            lists.erase(lists.begin()+i);
        }
        
        while(lists.size()){
            temp=lists[0];
            ind = 0;
            for(int i=0; i<lists.size(); i++){
                if(lists[i]->val < temp->val){
                    temp = lists[i];
                    ind = i;
                }
            }
                       
            if(ans){
                end->next = temp;
                end = temp;
                lists[ind] = lists[ind]->next;
            }
            else{
                ans = temp;
                end = temp;
                lists[ind] = lists[ind]->next;
            }
            
            if(lists[ind]==NULL) lists.erase(lists.begin()+ind);
            
        }
        
        return ans;
        
    
    }
};
