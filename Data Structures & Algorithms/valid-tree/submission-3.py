class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if not edges:
            return True

        node_map = {i:[] for i in range(n)}

        for n1, n2 in edges:
            node_map[n1].append(n2)
            node_map[n2].append(n1)

        visit = set()

        def dfs(i, prev):
            if i in visit:
                return False

            visit.add(i)

            for j in node_map[i]:
                if j == prev:
                    continue

                if not dfs(j, i):
                    return False

            return True

        return dfs(0, -1) and len(visit) == n
