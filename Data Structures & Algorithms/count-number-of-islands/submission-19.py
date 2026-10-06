class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
            
        rows = len(grid)
        cols = len(grid[0])
        res = 0

        def bfs(r, c):
            q = collections.deque()
            q.append((r, c))
            
            while q:
                row, col = q.popleft()
                directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

                for dr, dc in directions:
                    if (row + dr in range(rows) and
                        col + dc in range(cols) and
                        grid[row + dr][col + dc] == "1"):

                        q.append((row + dr, col + dc))
                        grid[row + dr][col + dc] = "0"

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1":
                    bfs(r, c)
                    res += 1

        return res
                
        