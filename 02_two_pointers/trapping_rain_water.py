def trap(height):
    left = 0
    right = len(height) - 1
    maxleft = height[left]
    maxright = height[right]
    water = 0

    while left < right:
        if maxleft <= maxright:
            left += 1
            maxleft = max(maxleft, height[left])
            water += maxleft - height[left]
        else:
            right -= 1
            maxright = max(maxright, height[right])
            water += maxright - height[right]

    return water


trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1])
