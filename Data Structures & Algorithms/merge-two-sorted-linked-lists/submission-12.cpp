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
        //handle cases where list1 or list2 are empty -> return the other list
        if(!list1) return list2;
        if(!list2) return list1;

        //create a linked list node obj w/ a dummy value
        ListNode merged(0);

        //init a reference ptr to the merged linked list obj
        ListNode* curr = &merged;

        //keep looping while both lists have not reached the end
        while(list1 && list2)
        {
            //compare values
            if(list1->val <= list2->val)
            {
                //this case is where list1 val is lower so append that result to merged
                curr->next = list1;

                //update the curr list1 ptr to point to the next node
                list1 = list1->next;
            }
            //otherwise list2 is lower
            else
            {
                //append list2 to merged
                curr->next = list2;
                
                //update list2 ptr to point to next node
                list2 = list2->next;
            }

            //iterate to the next node in merged
            curr = curr->next;
        }

        //append whatever list still has remaining nodes to merged
        if(list1) curr->next = list1;
        else if(list2) curr->next = list2;

        //return the next ptr of merged since that is the real start of the merged list
        return merged.next;
    }
};
