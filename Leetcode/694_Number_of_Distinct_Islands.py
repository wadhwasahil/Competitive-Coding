class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        visited = set()
        n = len(grid)
        m = len(grid[0])
        
        def explore(r, c, d = 0):
            if (0 <= r < n) and (0 <= c < m ) and (r, c) not in visited and grid[r][c]:
                visited.add((r, c))
                shape.append(d)
                explore(r + 1, c, 1)
                explore(r - 1, c, 2)
                explore(r, c + 1, 3)
                explore(r, c - 1, 4)
                shape.append(0)
        
        shapes = set()
        for i in range(n):
            for j in range(m):
                shape = []
                explore(i, j)
                if shape:
                    shapes.add(tuple(shape))
                    print(shape)
        return len(shapes)
                
