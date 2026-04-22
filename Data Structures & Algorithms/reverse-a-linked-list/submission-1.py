# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# iterating solution
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # def a prev pointer (where the curr node came from) and a curr pointer (current node)
        prev, curr = None, head

        # while curr is not null (has not reached end of list) continue loop
        while curr:
            # store the next node as next_ptr
            next_ptr = curr.next
            # set the current node's next ptr as the prev node
            curr.next = prev
            # set the prev node as the curr ptr
            prev = curr
            # set the curr node as the stored next ptr, moving forwards in the old linked list
            curr = next_ptr

        # once all the way done, curr = Null so return prev which should now be the head
        return prev
