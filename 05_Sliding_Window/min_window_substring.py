from collections import defaultdict


def minWindow(s: str, t: str) -> str:
    freq = defaultdict(int)
    needed = len(t)
    minlen = len(s) + 1
    start_index = 0

    # adding all frequncies of t in our freq map
    for ch in t:
        freq[ch] += 1

    left = 0
    right = 0

    while right < len(s):
        # decrementing frequency,
        freq[s[right]] -= 1

        if freq[s[right]] >= 0:
            # char in s also present in t
            needed -= 1

        right += 1
        while needed == 0:
            # now our window has all the characters from t
            length = right - left
            if length < minlen:
                minlen = length
                start_index = left
            # now shrink the window
            # first, increase back the frequency again
            freq[s[left]] += 1

            # now is freq is > 0 (ie, from 0 it became 1)
            if freq[s[left]] > 0:
                # that means that window does not contain all the chars
                # in t anymore, so we need to add chars from right and check again
                needed += 1

            # now increment left pointer
            left += 1

            # now, if needed is > 0, then it will again add from right and break out
            # of this inner while loop
            # otherwise, it will continue shrinking through the junk characters not needed
            # example, s = DBAOAEAODE, t = AAA
            # left will jump 2 places from D to A, as DB is not needed
            # however, s = ADBOAEAODE, t = AAA
            # left will only go from A to D, as after removing the first A, we need to again
            # add a character from right and check again

    answer = ""
    if minlen < len(s) + 1:
        answer = s[start_index : start_index + minlen]

    return answer


# here, even if we come across B two times, we dont change needed as the number of needed characters dont change
print(minWindow("ADOBECODEBANC", "ABC"))
