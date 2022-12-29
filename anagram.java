import java.util.*;

// Check if two strings are anagrams of each other
// Like: pile, lipe
// Since anagrams have same letters,
// both strings will give the same value after sorting

public class anagram {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) return false;
        
        char a[] = s.toCharArray();
        char b[] = t.toCharArray();

        Arrays.sort(a);
        Arrays.sort(b);

        for(int i = 0; i < s.length(); i++) {
            if(a[i] != b[i]) 
                return false;
        }

        return true;
    }
}