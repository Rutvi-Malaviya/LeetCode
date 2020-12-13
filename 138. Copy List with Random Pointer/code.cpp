/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL) return NULL;
        
        map<Node *, Node *> m;
        m[NULL] = NULL;
        
        Node *temp=head;
        
        while(temp){
            m[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        
        while(temp){
            Node *t = m[temp];
            t->next = m[temp->next];
            t->random = m[temp->random];
            temp = temp->next;
        }
        
        return m[head];
        
    }
};
