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
        //handle the cases where list1 or list 2 is empty
        if(list1 == nullptr) return list2;
        else if(list2 == nullptr) return list1;

        //init a dummy node that starts the list that will represent the merged list
        ListNode merged(0);

        //set the curr node to be the start of the merged list
        ListNode* curr = &merged;

        //keep iterating while list1 and list2 is not empty
        while(list1 && list2)
        {
            //check which node is smaller between list1 and 2
            if(list1->val <= list2->val)
            {
                //set curr to be the curr list1 node
                curr->next = list1;

                //update list1 to be the next node in the list
                list1 = list1->next;
            }
            else
            {
                //set curr to be the curr list2 node
                curr->next = list2;

                //update list2 to be the next node in the list
                list2 = list2->next;
            }

            //update curr to be the next node in merged
            curr = curr->next;
        }

        //append any remaining list elements to the end of the merged list
        if(list1 != nullptr) curr->next = list1;
        else if(list2 != nullptr) curr->next = list2;

        //return merged which should be the head of the whole list
        return merged.next;
    }
};
