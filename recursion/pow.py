def pow(x, n):
    """
    Get x^n, assuming n is non-negative
    """
    if n == 0:
        return 1
    else:
        return x * pow(x, n - 1)


print(pow(2, 32))
