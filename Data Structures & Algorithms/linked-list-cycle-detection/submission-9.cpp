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
        //handle situations where head is either empty or just size 1
        if(!head || !head->next) return false;

        //set a slow and fast node tracker w/ both starting at the head
        ListNode* slow = head;
        ListNode* fast = head;

        //keep going while both fast and its next node are not null
        while(fast && fast->next)
        {
            //iterate slow by 1 node
            slow = slow->next;

            //iterate fast by 2 nodes
            fast = fast->next->next;

            //if slow == fast then return true
            if(slow == fast) return true;
        }

        //if loop finished then no cycle -> return false
        return false;
    }
};
