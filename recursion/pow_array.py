def pow_array(x, n):
    """
    Given n, return [x^0, x^1, x^2, ..., x^n]
    """
    if n == 0:
        return [1]
    else:
        prev = pow_array(x, n - 1)
        prev.append(x * prev[-1])
        return prev


print(pow_array(2, 64))
