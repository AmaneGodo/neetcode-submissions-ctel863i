class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        q = deque()

        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 0:
                    q.append((r, c))


        while q:
            r, c = q.popleft()

            directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

            for dr, dc in directions:
                if (r + dr in range(len(grid)) and
                    c + dc in range(len(grid[0])) and 
                    grid[r + dr][c + dc] == 2147483647):
                        grid[r + dr][c + dc] = 1 + grid[r][c]
                        q.append((r + dr, c + dc))
