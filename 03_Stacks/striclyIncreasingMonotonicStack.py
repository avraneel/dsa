def striclyIncreasingMonotonicStack(nums: list):
    """
    This program demonstrates the working of a strictly increasing
    monotonic stack
    """
    stack = []
    for i in range(len(nums)):
        # while stack is non empty and condition for pop is there
        while stack and stack[-1] >= nums[i]:
            # element to be inserted is greater, so pop it
            print(f"For {nums[i]}, so we need to pop")
            item = stack.pop()
            index = i
            print(f"Item popped: {item}")

        # we are gonna push every element, after all
        stack.append(nums[i])

        print(f"Stack state now: {stack}")


print(striclyIncreasingMonotonicStack([1, 7, 9, 5]))
print()
print(striclyIncreasingMonotonicStack([3, 1, 4, 2, 5]))
