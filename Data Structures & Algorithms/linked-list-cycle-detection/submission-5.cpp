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
    bool hasCycle(ListNode* head) {
        // if the list is empty or just 1 node, return false
        if(!head || !head->next)
        {
            return false;
        }

        // create a slow ptr which moves one node at a time and a fast ptr moving 2 nodes at a time
        // point both to the head node
        ListNode* slow = head;
        ListNode* fast = head;

        // keep iterating while both the fast ptr and its next ptr are valid
        // this is the stop clause since fast moves 2 nodes at a time, both fast and its next need to be
        // valid for the loop to continue w/ out throwing an error
        while(fast && fast->next)
        {
            // iterate the two ptrs
            slow = slow->next;
            fast = fast->next->next;

            // if the two ptrs are pointing at the same node then return true for there is a cycle
            if(slow == fast)
            {
                return true;
            }
        }

        // if loop ended then that means there was no loop so return false
        return false;
    }
};
