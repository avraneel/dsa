#include <bits/stdc++.h>
using namespace std;

/**
 * Link: https://leetcode.com/problems/permutation-in-string/description/
 *
 * This is SUBOPTIMAL O(26n) approach! (SEE THE SECOND SOLUTION)
 *
 * To find out if one string is a perm of another string, we make freq hashmap
 * and increment freq if char belongs to 1st string,
 * and decrement freq if char belonfs to 2nd string. (Refer to Anagram program in hashing section)
 *
 * We can use this logic and also keep in mind that the size of the sliding window will be
 * equal to the shorter string
 */
bool checkInclusion(string s1, string s2)
{
    int left = 0;
    int right = s1.length() - 1;

    // building freq map of s1
    unordered_map<char, int> freq;
    for (auto &ch : s1)
        freq[ch]++;

    while (right < s2.length())
    {
        // even if we do freq[ch]-- like in anangram, we still new a new hm, for each window,
        // so better to create a separate hm for window freshly
        vector<int> window(s2.begin() + left, s2.begin() + right + 1);
        unordered_map<char, int> windowFreq;

        for (auto &ch : window)
            windowFreq[ch]++;

        // check if both maps are equal
        if (freq != windowFreq)
        {
            // slide the window
            left++;
            right++;
        }
        else
        {
            return true;
        }
    }
    return false;
}

/**
 * This is THE OPTIMAL O(n) approach
 * As usual, size of sliding window is always fixed to be size of s1
 *
 */
bool checkInclusionMatches(string s1, string s2)
{
    if (s1.length() > s2.length())
        return false;

    int s1Freq[26] = {0};
    int s2Freq[26] = {0};

    // For fist sliding window
    for (int i = 0; i < s1.length(); i++)
    {
        s1Freq[s1[i] - 'a']++;
        s2Freq[s2[i] - 'a']++;
    }

    int matches = 0;
    for (int i = 0; i < 26; i++)
    {
        if (s1Freq[i] == s2Freq[i])
            matches++;
    }

    int left = 0;

    for (int right = s1.length(); right < s2.length(); right++)
    {
        // so, starting from the next character after sliding window
        // (ie, we start from inchworm expands by 1)
        if (matches == 26)
            return true;

        // updating frequency for new right
        int index = s2[right] - 'a';
        s2Freq[index]++;
        // new freq can be equal
        // eg, s2 = "acb", s1 = "ab"
        if (s2Freq[index] == s1Freq[index])
            matches++;
        // adding a new right, new freq can be overshot
        // eg, s2 = "cbb", s1 = "ab"
        else if (s2Freq[index] == s1Freq[index] + 1)
            matches--;

        // updating frequency for new left
        index = s2[left] - 'a';
        s2Freq[index]--;
        // now for that character, new freq can be equal
        // eg, s2 = "cab", s1 = "ab", so c is now 0 for both
        if (s2Freq[index] == s1Freq[index])
            matches++;
        // removing a new left, new freq is now lower
        // eg, s2 = "abc", s1 = "ac"
        if (s2Freq[index] + 1 == s1Freq[index])
            matches--;

        // now actually removing the character
        left++;
    }

    return matches == 26;
}

int main()
{
    cout << checkInclusionMatches("ab", "eidbaooo") << "\n";
    cout << checkInclusionMatches("ab", "eidboaoo") << "\n";
}