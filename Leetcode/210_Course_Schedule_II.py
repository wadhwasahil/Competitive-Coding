class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj_mat = [[] for _ in range(numCourses)]
        for i, j in prerequisites:
            adj_mat[i].append(j)
        visited = [0 for _ in range(numCourses)]
        op = []
        self.is_possible = True
        processed_nodes = set()
        def dfs(i):
            if i in processed_nodes:
                self.is_possible = False
                return
            if visited[i]:
                return 
            processed_nodes.add(i)
            visited[i] = 1
            for j in adj_mat[i]:
                dfs(j)
            processed_nodes.discard(i)
            op.append(i)
        for i in range(numCourses):
            if not visited[i]:
                dfs(i)
                if not self.is_possible:
                    return []
        return op
        
        
