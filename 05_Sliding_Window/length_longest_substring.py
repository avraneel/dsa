def lengthOfLongestSubstring(s):
    """
    Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/ \n
    Let's say we have `left ... k ... right` where \n
    `s[right] = s[k]`, so we have to move `left` to `k + 1` index
    """

    left = 0
    maxlen = 0
    lastSeenIndex = [-1] * 128
    # assuming all 128 ascii characters

    for right in range(len(s)):
        if lastSeenIndex[ord(s[right])] >= left:
            # character present in left to right - 1 index (our sliding window)
            left = lastSeenIndex[ord(s[right])] + 1
        # then, or otherwise, update the last seen index and length accordingly
        lastSeenIndex[ord(s[right])] = right
        maxlen = max(maxlen, right - left + 1)

    return maxlen


print(lengthOfLongestSubstring("abcabcbb"))
print(lengthOfLongestSubstring("abcba"))
