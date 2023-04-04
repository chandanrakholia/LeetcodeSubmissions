// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;

        ListNode* temp=head;
        ListNode* ans=temp;
        while(temp->next!=NULL){
            if(temp->next->val==val){
                ListNode* t=temp->next->next;
                delete(temp->next);
                temp->next=t;
            }
            else
            temp=temp->next;
        }
        if(head->val==val)
        return ans->next;
        else{
            return ans;
        }
        
    }
};