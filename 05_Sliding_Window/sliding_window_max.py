import collections


class Solution:
    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
        res = []
        q = collections.deque()

        l = 0
        r = 0

        while r < len(nums):
            # pop smaller values less than q
            while q and nums[q[-1]] < nums[r]:
                q.pop()

            q.append(r)

            # remove left from window
            if l > q[0]:
                q.popleft()

            if (r + 1) >= k:
                res.append(nums[q[0]])
                l += 1

            r += 1

        return res
