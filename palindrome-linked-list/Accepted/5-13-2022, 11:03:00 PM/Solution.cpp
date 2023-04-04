// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    if (fast)
      slow = slow->next;
    slow = reverseList(slow);

    while (slow) {
      if (slow->val != head->val)
        return false;
      slow = slow->next;
      head = head->next;
    }

    return true;
  }

 private:
  ListNode* reverseList(ListNode* head) {
    ListNode* previous = NULL;

    while (head) {
      ListNode* next = head->next;
      head->next = previous;
      previous = head;
      head = next;
    }

    return previous;
  }
};