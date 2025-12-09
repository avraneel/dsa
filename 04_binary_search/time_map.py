# https://leetcode.com/problems/time-based-key-value-store/

from collections import defaultdict

class TimeMap:

    def __init__(self):
        self.map = defaultdict(list)

    def set(self, key:str, value:str, timestamp:int) -> None:
        self.map[key].append([timestamp, value])

    def get(self, key: str, timestamp: int) -> str: 
        arr = self.map[key]

        if not arr:
            return ''

        left, right = 0, len(arr) - 1

        while left <= right:
            mid = (left + right) // 2
            if arr[mid][0] == timestamp:
                return arr[mid][1]
            if arr[mid][0] < timestamp:
                left = mid + 1
            else:
                right = mid - 1
        

        if arr[right][0] > timestamp:
            return ""
            
        return arr[right][1]



mymap = TimeMap()

mymap.set("foo", "bar", 1)

mymap.get("foo", 1)