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
        //reference the head as curr and the prev node as null
        ListNode* curr = head;
        ListNode* prev = nullptr;

        //keep going while the curr node is not null
        while(curr != nullptr)
        {
            //create a reference to the curr node's next ptr
            ListNode* next_ptr = curr->next;

            //update curr's next ptr to be the prev ptr
            curr->next = prev;
            //update the prev node to be the curr node
            prev = curr;
            //update curr to be the next ptr
            curr = next_ptr;
        }

        //once through the prev ptr should be the head of the list
        return prev;
    }
};
