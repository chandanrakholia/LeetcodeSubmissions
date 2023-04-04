// https://leetcode.com/problems/merge-two-sorted-lists

/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ans = new ListNode(-1);
        ListNode* final=ans;
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        if(list1==NULL) return list2;
        if(list2==NULL) return  list1;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val <= temp2->val)
            {
                ans->next = temp1;
                temp1 = temp1->next;
                ans=ans->next;
            }
            else
            {
                ans->next = temp2;
                temp2 = temp2->next;
                ans=ans->next;
            }
        }
        if (temp1 != NULL)
        {
            while (temp1 != NULL)
            {
                ans->next = temp1;
                temp1 = temp1->next;
            }
        }
        if (temp2 != NULL)
        {
            while (temp2 != NULL)
            {
                ans->next = temp2;
                temp2 = temp2->next;
            }
        }
        return final->next;
    }
};
// @lc code=end
