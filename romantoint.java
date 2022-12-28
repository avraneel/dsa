import java.util.*;

class romanToint {
    public int romanToInt(String s) {
        int ans = 0;

        Map<String,Integer> m = new HashMap<String, Integer>();
        m.put("I", Integer.valueOf(1));
        m.put("V", Integer.valueOf(5));
        m.put("X", Integer.valueOf(10));
        m.put("L", Integer.valueOf(50));
        m.put("C", Integer.valueOf(100));
        m.put("D", Integer.valueOf(500));
        m.put("M", Integer.valueOf(1000));

        boolean flag = false;

        for(int i = 0; i < s.length() - 1; i++) {
            String s1 = s.charAt(i) + "";
            String s2 = s.charAt(i+1) + "";
            if(m.get(s1) < m.get(s2)) {
                ans += m.get(s2)-m.get(s1);
                i++;
                if(i == s.length()-1)
                    flag = true;
            }
            else {
                ans += m.get(s1);
            }
        }

        if(flag == false)
            ans += m.get(s.charAt(s.length()-1) + "");

        return ans;
    }
}
