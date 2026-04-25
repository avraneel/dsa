# Link: https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1

def next_smaller(arr):
    stack = []
    smaller = [-1] * len(arr)

    for i in range(len(arr)):
        while stack and arr[stack[-1]] > arr[i]:
            index = stack.pop()
            smaller[index] = arr[i]

        stack.append(i)

    return nextSmaller
