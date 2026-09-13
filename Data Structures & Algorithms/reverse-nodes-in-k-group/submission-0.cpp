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
    ListNode* reverse(ListNode* head){
        ListNode* cur=head,*prev=nullptr,*nex=nullptr;
        while(cur){
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* prevgroupend = dummy;
        while(true){
            ListNode* kthnode = prevgroupend;
            for(int i=0;i<k && kthnode;i++){
                kthnode = kthnode->next;
            }
            if(!kthnode) break;
            ListNode* groupstart = prevgroupend->next;
            ListNode* nextgroupstart = kthnode->next;
            kthnode->next = nullptr;
            ListNode* newgrouphead = reverse(groupstart);
            prevgroupend->next = newgrouphead;
            groupstart->next = nextgroupstart;
            prevgroupend = groupstart;
        }
        return dummy->next;
    }
};
