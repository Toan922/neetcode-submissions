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
        //keep track of the curr node we are looking at and the prev node
        ListNode* curr = head;
        ListNode* prev = nullptr;

        //keep looping while the curr head is not null
        while(curr)
        {
            //keep track of the next node as the curr node's next ptr
            ListNode* nextptr = curr->next;

            //set the curr node's next ptr to be the prev node
            curr->next = prev;

            //update the prev node to be the curr node
            prev = curr;

            //move onto the next node to be reversed by updating curr
            curr = nextptr;
        }

        //return prev since curr will now be pointing to null
        return prev;
    }
};
