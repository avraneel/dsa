#include <bits/stdc++.h>
using namespace std;

/**
 * Function to check if b is a permutation of a
 * Take a frequency hashmap, if belongs to a then increment
 * if belongs to b then decrement
 *
 * Kinda related to anagram
 */
bool isPermut(string a, string b)
{
    unordered_map<char, int> freq;

    for (int i = 0; i < a.length(); i++)
    {
        freq[a[i]]++;
        freq[b[i]]--;
    }

    for (auto &pair : freq)
    {
        if (pair.second != 0)
            return false;
    }

    return true;
}

int main()
{
    cout << isPermut("abcdde", "daedbc") << "\n";
    cout << isPermut("aboab", "bbaac") << "\n";
}
