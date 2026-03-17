# Link https://leetcode.com/problems/longest-repeating-character-replacement/description/

from collections import defaultdict


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        """
        For each substring, we take the frequency of the most occuring character as f
        so no. of replacements should be s.length - f <= k.

        For the sliding window, if above condition is satisfied then increment right
        If not satisfied then decrease frequency of s[l] and then, increment l
        """
        left = 0
        right = 0
        maxlen = 0
        freq = defaultdict(int)
        maxf = 0
        n = len(s)

        for right in range(n):
            freq[s[right]] += 1
            maxf = max(maxf, freq[s[right]])
            # calculate max f here
            if (right - left + 1) - maxf > k:
                freq[s[left]] -= 1
                left += 1
            maxlen = max(maxlen, right - left + 1)

        return maxlen
