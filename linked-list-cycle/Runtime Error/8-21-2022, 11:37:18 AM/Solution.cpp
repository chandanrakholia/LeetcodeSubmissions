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
        bool ans=false;
        while(fast!=NULL && slow!=NULL){
            if(fast==slow){
                ans=true;
                break;
            }
            fast=fast->next->next;
            slow=slow->next;
        }
        if(head->next==NULL) return false;
        else
        return ans;
    }
};