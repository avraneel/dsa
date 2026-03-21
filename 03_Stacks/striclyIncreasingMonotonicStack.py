def striclyIncreasingMonotonicStack(nums: list):
    """
    This program demonstrates the working of a strictly increasing
    monotonic stack. Keep in mind the stack holds the index!
    """
    stack = []
    for i in range(len(nums)):
        # while stack is non empty and condition for pop is there
        while stack and nums[stack[-1]] > nums[i]:
            # element to be inserted is greater, so pop it
            print(f"For {nums[i]}, so we need to pop")
            index = stack.pop()
            print(f"Index popped: {index}, Item popped: {nums[index]}")

        # we are gonna push every element, after all
        # so the stack hold the INDEX of that element
        stack.append(i)

        print(f"Stack state now: {stack}")
        print(f"Elements according to stack are: {[nums[i] for i in stack]}")


print(striclyIncreasingMonotonicStack([1, 7, 9, 5]))
print()
print(striclyIncreasingMonotonicStack([3, 1, 4, 2, 5]))
