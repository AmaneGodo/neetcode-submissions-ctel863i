class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        rows = len(grid)
        cols = len(grid[0])
        maxArea = 0

        def bfs(r, c):
            q = deque()
            q.append((r, c))
            grid[r][c] = 0
            area = 1

            while q:
                row, col = q.popleft()
                directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

                for dr, dc in directions:
                    nxt_r, nxt_c = row + dr, col + dc

                    if (
                        nxt_r in range(rows) and 
                        nxt_c in range(cols) and 
                        grid[nxt_r][nxt_c] == 1
                    ):
                    
                        area += 1
                        grid[nxt_r][nxt_c] = 0
                        q.append((nxt_r, nxt_c))

            return area

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    maxArea = max(maxArea, bfs(r, c))

        return maxArea
        

        