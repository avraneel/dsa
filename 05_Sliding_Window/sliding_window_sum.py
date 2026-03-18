def sliding_window_sum(arr, n):
    """
    Given a sliding window of size n, runs it through the entire array and
    prints out the sum each time.
    """
    left = 0
    right = n - 1

    while right < len(arr):
        window = arr[left : right + 1]
        print(f"Window = {window}, Sum = {sum(window)}")
        left += 1
        right += 1


sliding_window_sum([1, 2, 3, 4, 5, 6, 7, 8, 9], 3)
