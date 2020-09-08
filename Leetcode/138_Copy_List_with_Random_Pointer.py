"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head == None:
            return None
        ptr = head
        while ptr:
            new_node = Node(ptr.val, None, None)
            new_node.next = ptr.next
            ptr.next = new_node
            ptr = ptr.next.next
            
        ptr = head
        while ptr:
            ptr.next.random = ptr.random.next if ptr.random else None
            ptr = ptr.next.next
            
        old_ptr = head
        head_old = head.next
        new_ptr = head.next
        while old_ptr:
            old_ptr.next = old_ptr.next.next
            new_ptr.next = new_ptr.next.next if new_ptr.next else None
            old_ptr = old_ptr.next
            new_ptr = new_ptr.next
            
        return head_old
            
