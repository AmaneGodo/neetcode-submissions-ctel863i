class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count = Counter(tasks)
        hq = [-cnt for cnt in count.values()]
        heapq.heapify(hq)

        time = 0
        q = deque()

        while hq or q:
            time += 1

            if not hq:
                time = q[0][1]

            else:
                cnt = 1 + heapq.heappop(hq)

                if cnt != 0:
                    q.append([cnt, time + n])

            if q and q[0][1] == time:
                heapq.heappush(hq, q.popleft()[0])

        return time