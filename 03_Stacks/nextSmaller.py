def nextSmaller(arr):
    stack = []
    nextSmaller = [-1] * len(arr)

    for i in range(len(arr)):
        while stack and arr[stack[-1]] > arr[i]:
            index = stack.pop()
            nextSmaller[index] = arr[i]

        stack.append(i)

    return nextSmaller
