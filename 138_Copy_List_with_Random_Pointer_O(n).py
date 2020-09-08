"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def __init__(self):
        self.visited = {}
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head == None:
            return None
        if head in self.visited:
            return self.visited[head]
        
        node = Node(head.val, None, None)
        
        self.visited[head] = node
        
        node.random = self.copyRandomList(head.random)
        node.next = self.copyRandomList(head.next)
        
        return node
