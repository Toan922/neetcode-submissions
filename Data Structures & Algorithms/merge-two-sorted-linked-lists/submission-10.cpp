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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if list 1 is empty, return list 2
        if(!list1)
        {
            return list2;
        }
        // same logic for if list 2 is empty
        else if(!list2)
        {
            return list1;
        }

        // create a dummy starter node w val 0 for the merged list
        ListNode merged(0);
        // create a node pointer that has the address of the dummy node/curr head
        ListNode* curr = &merged;

        // continue iterating while list1 and list2 still have stuff
        while(list1 && list2)
        {
            // check which value is lower since this is ASC order
            if(list1->val <= list2->val)
            {
                // if list1 is lower or equal then set curr next to be list1's curr node
                curr->next = list1;
                // iterate list1 to next node
                list1 = list1->next;
            }
            // otherwise list2 is lower
            else
            {
                // same logic as when if list1 was lower
                curr->next = list2;
                list2 = list2->next;
            }

            // iterate current to next node
            curr = curr->next;
        }

        // if list 1 is still not empty then append it to the end of merged list;
        if(list1)
        {
            curr->next = list1;
        }
        // same thing if list2 is not empty
        else if(list2)
        {
            curr->next = list2;
        }

        // return the NEXT ptr of dummy since it is the actual head of the list
        // use . not -> since this is an obj and not an obj ptr
        return merged.next;
    }
};
