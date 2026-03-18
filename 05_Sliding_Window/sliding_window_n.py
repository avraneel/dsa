def slidingWindow(arr, n):
    """
    Function that prints the sliding window of size n
    through the array arr
    """
    left = 0
    right = n - 1

    if n >= len(arr):
        print(arr)

    while right < len(arr):
        window = arr[left : right + 1]
        print(f"Window = {window}")
        left += 1
        right += 1


slidingWindow([1, 2, 3, 4, 5, 6, 7, 8, 9], 3)
