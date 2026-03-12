def merge(left, right):
    merged = []
    left_pointer = 0, right_pointer = 0
    while left_pointer < len(left) and right_pointer < len(right):
        # Loop as long as both pointers point within array
        if left[left_pointer] < right[right_pointer]:
            # add smaller element to merged array and update corresponding pointer
            merged.append(left[left_pointer])
            left_pointer += 1
        else:
            # add smaller element to merged array and update corresponding pointer
            merged.append(right[right_pointer])
            right_pointer += 1
    if left_pointer >= len(left):
        # left array exhausted, copy everything remaining from right subarray
        return merged + left[left_pointer:]
    else:
        # right array exhausted, copy everything remaining from left subarray
        return merged + right[right_pointer:]

def mergesort(arr):
    if len(arr) <= 1:
        return arr
    else:
        left = arr[:len(arr) // 2]
        right = arr[len(arr) // 2:]
        return merge(left, right)
