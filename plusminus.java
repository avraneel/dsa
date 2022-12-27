import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'plusMinus' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static void plusMinus(List<Integer> arr) {
    // Write your code here
        int a = 0, b =0, c = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr.get(i) < 0) {
                a++;
            }
            else if(arr.get(i) > 0) {
                b++;
            }
            else {
                c++;
            }
        }
        String ax = (double)a/arr.size() + " ";
        if(ax.length() > 6)
            ax = ax.substring(0,8);
        String bx = (double)b/arr.size() + " ";
        if(bx.length() > 6)
            bx = bx.substring(0,8);
        String cx = (double)c/arr.size() + " ";
        if(cx.length() > 6)
            cx = cx.substring(0,8);
        System.out.println(bx);
        System.out.println(ax);
        System.out.println(cx);
    }

}

public class plusminus {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        Result.plusMinus(arr);

        bufferedReader.close();
    }
}

