# Link: https://leetcode.com/problems/mirror-frequency-distance/description/

from collections import defaultdict


def mirrorFrequency(s: str):
    # store all freq in hashmap
    ans = 0
    mp = defaultdict(int)
    for ch in s:
        mp[ch] += 1

    # now iterate and flag all visited ones
    for c in s:
        if mp[c] < 0:
            continue
        if ord(c) >= 97 and ord(c) <= 122:
            # lowercase english
            m = chr(219 - ord(c))

        elif ord(c) >= 48 and ord(c) <= 57:
            # digit
            m = chr(105 - ord(c))

        freq_c = mp[c]
        freq_m = mp[m]
        diff = abs(freq_c - freq_m)
        ans += diff
        mp[c] = -1  # mark visited
        mp[m] = -1  # mark visited

    return ans


print(mirrorFrequency("ab1z9"))
print(mirrorFrequency("4m7n"))
print(mirrorFrequency("byby"))
print(mirrorFrequency("kk"))
print(mirrorFrequency("26"))
