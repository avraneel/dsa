import java.util.*;

// Link: https://leetcode.com/problems/isomorphic-strings/description/

class isomorphic {
    public boolean isIsomorphic(String s, String t) {

        // Take 2 HMaps, 1 where s is key t is value and vice versa
        HashMap<String, String> m1 = new HashMap<>();
        HashMap<String, String> m2 = new HashMap<>();

        if(s.length() != t.length()) return false;

        // In first iteration you put the values
        // The second o in "foo" will map to "r" and so
        // "o" -> "a" will update to "o" -> "r"
        for(int i = 0; i < s.length(); i++) {
            m1.put(s.charAt(i) + "", t.charAt(i) + "");
            m2.put(t.charAt(i) + "", s.charAt(i) + "");
        }

        // In second iteration you check whether, whether all the occurences of 
        // a character map to the same value or not. 
        // "foo" will check that it's first "o" is mapped to "r", 
        // but it should be mapped to "a" instead !! 
        for(int i = 0; i < s.length(); i++) {
            String a = t.charAt(i) + "";
            String b = s.charAt(i) + "";
            if(!(a.equals(m1.get(b)) && b.equals(m2.get(a))))
                return false;
        }
        return true;
    }
}