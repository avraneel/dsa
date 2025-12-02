"""
piles = [5]
hours = [4]

min speed = [1]
max speed = [5]

set ans = 5

Step 1: middle speed = 1 + 5 // 2 = 3
Step 2: does 3 work? ceil(5/3) = 1.xx = 2 hours
Step 3: time 2 is less than 4
store ans = 3
find a lower speed. (lower = 1, upper = 3)

It speed is low, it is still possible to finish in that speed, so in the next 
search space we keep speed 3 into account, so we do upper = mid

Step 4: new search range = [1,2,3]
Step 5: new middle speed = 2 (as 1 + 3 // 2 = 2)

Step 6: does speed 1 work? ceil(5/2) = 2.xx = 3 hours
Step 7: time 3 is less than 4
set speed = 2
find a lower speed (lower = 1, upper = 2 - 1 = 1)

Step 8: new search range = [1]
Step 9: new middle speed = 1 (as 1 + 1 // 2 = 1)

Step 10: does speed 1 work? ceil(5/1) = 5
Step 11: time 5 is more than 4

find a higher speed. (lower = 1 + 1 = 2, upper = 1)

loop terminated as lower(2) > upper (1)
"""

import math

def minEatingSpeed(piles, h):
    lower = 1
    upper = max(piles)
    
    ans = max(piles)

    while lower < upper:
        mid_speed = (lower + upper) // 2
        total_time = 0

        for pile in piles:
            time = math.ceil(pile / mid_speed)
            total_time += time
        
        if total_time <= h:
            """
            If speed is too fast, it is still possible to finish in that speed, so in the next 
            search space we keep speed 3 into account, so we do upper = mid
            """
            upper = mid_speed
            ans = mid_speed
        elif total_time > h:
            """
            However if the speed is too slow, that particular speed will not
            work so we can eliminate it from the search space in the next iteration.
            So we do lower = mid + 1
            """
            lower = mid_speed + 1

            
    return ans

    print(mid_speed)
            
print(minEatingSpeed([5],4))