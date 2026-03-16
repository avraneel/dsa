#include <bits/stdc++.h>
using namespace std;

/**
 * Let's say we have left ... k ... right where
 * s[right] = s[k], so we have to move left to k + 1 index
 */
int lengthOfLongestSubstring(string s)
{
    int left = 0;
    int maxlen = 0;
    vector<int> lastSeenIndex(128, -1); // assuming all 128 ascii characters

    for (int right = 0; right < s.length(); right++)
    {
        if (lastSeenIndex[s[right]] >= left)
        {
            // character present in left to right - 1 index (our sliding window)
            left = lastSeenIndex[s[right]] + 1;
        }
        // then, or otherwise, update the last seen index and length accordingly
        lastSeenIndex[s[right]] = right;
        maxlen = max(maxlen, right - left + 1);
    }

    return maxlen;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << "\n";
    cout << lengthOfLongestSubstring("abcba") << "\n";
}