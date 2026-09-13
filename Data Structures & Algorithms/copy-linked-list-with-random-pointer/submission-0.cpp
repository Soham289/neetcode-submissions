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
       if(!head) return nullptr;
       unordered_map<Node*,Node*> oldtonew;
       Node* cur = head;
       while(cur){
            oldtonew[cur]=new Node(cur->val);
            cur=cur->next;
       }
       cur=head;
       while(cur){
        oldtonew[cur]->next = oldtonew[cur->next];
        oldtonew[cur]->random = oldtonew[cur->random];
        cur = cur->next;
       }
       return oldtonew[head];
    }
};
