class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if len(intervals) < 2:
            return len(intervals)
        n = len(intervals)
        intervals = sorted(intervals, key = lambda x: x[0])
        hq = []
        heapq.heappush(hq, intervals[0][1])
        for i in range(1, n):
            top = heapq.heappop(hq)
            s, e = intervals[i]
            if top <= s:
                heapq.heappush(hq, e)
            else:
                heapq.heappush(hq, top)
                heapq.heappush(hq, e)
        return len(hq)
