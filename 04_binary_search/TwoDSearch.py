# Take the row numbers as mid

def search_2d(key, matrix):

    m = len(matrix)
    n = len(matrix[0])
    l = 0
    r = (m*n) - 1

    while (l<=r):
        mid = (l + r) // 2

        # we are not flattening the array in memory
        # we are just calculating the corresponding row and col according to mid
        # and yes, value of m is not used here
        # keep these formulas in mind
        row = mid // n
        col = mid % n

        if key == matrix[row][col]:
            return True
        
        elif key < matrix[row][col]:
            r = mid-1

        else:
            l = mid+1

    return False
    


print(search_2d(13, 
              [[1,2,3,4,5], 
               [6,7,8,9,10], 
               [11,12,13,14,15], 
               [16,17,18,19,20], 
               [21,22,23,24,25],
               [26,27,28,29,30]]))
