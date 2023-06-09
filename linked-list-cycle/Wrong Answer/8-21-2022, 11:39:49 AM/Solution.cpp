// https://leetcode.com/problems/linked-list-cycle

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
    bool hasCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        if(head==NULL || head->next==NULL) return false;
        bool ans=false;
        while(fast!=NULL && slow!=NULL){
            if(fast==slow){
                return true;
                break;
            }
            fast=fast->next->next;
            slow=slow->next;
        }
        return false;
    }
};