def binary_search(key, nums):

    l = 0
    r = len(nums)-1

    # l <= r to account for arrays of length 1
    while l <= r:
        mid = (l + r) // 2

        # if == mid then found
        if key == nums[mid]:
            return mid

        #if < mid
        if key < nums[mid]:
            r = mid-1

        else:
            l = mid+1

    return -1

print(binary_search(3, [1,2,3,4,5,6,7,8,9]))
