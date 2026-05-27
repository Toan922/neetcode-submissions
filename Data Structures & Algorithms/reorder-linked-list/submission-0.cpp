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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        while(secondHalf)
        {
            ListNode* nextPtr = secondHalf->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = nextPtr;
        }

        secondHalf = prev;

        while(secondHalf)
        {
            ListNode* nextPtr = head->next;
            head->next = secondHalf;
            ListNode* secondNext = secondHalf->next;
            secondHalf->next = nextPtr;
            head = nextPtr;
            secondHalf = secondNext;
        }
    }
};
