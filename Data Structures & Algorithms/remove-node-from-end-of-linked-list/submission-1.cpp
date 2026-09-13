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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==1 && !head->next) return nullptr;
        int count=0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp=temp->next;
        }
        if (count == n) {
            ListNode* node = head;
            head = head->next;
            delete node;
            return head;
        }
        temp=head;
        int to_delete = count-n;
        temp = head;
        for (int i = 1; i < to_delete; ++i) {
            temp = temp->next;
        }
        ListNode* node = temp->next;
        temp->next=temp->next->next;
        delete(node);
        return head;

    }
};
