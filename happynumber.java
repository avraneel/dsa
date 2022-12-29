// Since it will lead endlessly to a cycle if not happy, we can use fast and slow pointer like LL cycle detection
// Link: https://leetcode.com/problems/happy-number/description/

public class happynumber {
    public boolean isHappy(int n) {
        int s = n;
        int f = n;

        do {
            s = sumsqdigit(s);  // slow will compute 1x
            f = sumsqdigit(sumsqdigit(f));  // fast will compute 2x

            if(s == 1)      // check happy with slow 
                return true;
        } while(s != f);

        return false;
    }

    int sumsqdigit(int n) {
        int sum = 0;
        while(n != 0) {
            int d = n % 10;
            sum += (d*d);
            n /= 10;
        }
        return sum;
    }
}
