def findGoodIntegers(n):
    if n <= 578:
        return []

    largest = 0
    # cube root of a number must be atmost less than n//2
    for i in range(9, n // 2):
        if (i**3) < n:
            largest = i

        other = n - largest
