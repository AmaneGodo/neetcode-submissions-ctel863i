class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count = Counter(tasks)
        max_hq = [-cnt for cnt in count.values()]
        heapq.heapify(max_hq)

        time = 0
        q = deque()
        while max_hq or q:
            time += 1

            if not max_hq:
                time = q[0][1]

            else:
                cnt = 1 + heapq.heappop(max_hq)

                if cnt != 0:
                    q.append([cnt, time + n])

            if q and q[0][1] == time:
                heapq.heappush(max_hq, q.popleft()[0])

        return time