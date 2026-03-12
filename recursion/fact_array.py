def fact_array(n):
    """
    Given n, find out [1!, 2!, ..., n!]
    """
    if n <= 1:
        return [1]
    else:
        prev_array = fact_array(n - 1)  # Get array from [1!, 2!, ..., n-1!]
        curr = prev_array[-1] * n  # Calculate nth term
        prev_array.append(curr)  # Add it to the previously returned array
        return prev_array


print(fact_array(5))
