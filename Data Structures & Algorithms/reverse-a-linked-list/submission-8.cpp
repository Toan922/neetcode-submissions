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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr)
        {
            // create a temp var holding the next node
            ListNode* next = curr->next;
            // reverse the current node's next node
            curr->next = prev;
            // set the previous node to now be the curr node
            prev = curr;
            // move the current node to the old next
            curr = next;
        }

        // return prev since curr would be nullptr
        return prev;
    }
};
