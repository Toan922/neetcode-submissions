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
        //finding the middle via slow and fast ptrs
        ListNode* slow = head;
        ListNode* fast = head->next;

        //iterate these until you run out of the fast ptr
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //this places your slow ptr's next node as the beginning of the second half
        //second represents the second half's head
        ListNode* second = slow->next;

        //point the tail of the first half's next node to be null
        slow->next = nullptr;

        //declaring a ptr representing the prev node to reverse the linked list
        ListNode* prev = nullptr;

        //we want to reverse the second half to allow for easier list merging
        while(second)
        {
            //declare a temp var that stores what the current next node is so we can iterate to it
            ListNode* nextPtr = second->next;
            //reverse the nextPtr to point instead to the current prev node
            second->next = prev;
            //update prev to be the current node
            prev = second;
            //update current node to be the stored next node
            second = nextPtr;
        }

        //since we iterated past the head node we want second to instead be prev since prev = current head
        second = prev;

        //begin merging the two linked lists together
        //keep iterating until second is null
        while(second)
        {
            //declare the temp vars that represent the first half & second half's next ptrs
            ListNode* firstNext = head->next;
            ListNode* secondNext = second->next;

            //point the current head's next to be second's current head
            head->next = second;

            //point second's next to be the stored next from the first half
            second->next = firstNext;

            //iterate the pointers to move to each linked list's respective next nodes
            head = firstNext;
            second = secondNext;
        }

        //return nothing it should be a completely merged together linked list
    }
};
