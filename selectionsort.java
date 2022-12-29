public class selectionsort {
    public static void main(String[] args) {
        int arr[] = {9,5,3,8,1,11,7,2};
        int n = arr.length;

        for(int i = 0; i < n; i++) {
            int min_ind = i;
            for(int j = i; j < n; j++) {
                if(arr[j] < arr[min_ind]) 
                    min_ind = j;
            }
            int t = arr[i];
            arr[i] = arr[min_ind];
            arr[min_ind] = t;
        }

        for(int i = 0; i < n; i++) {
            System.out.println(arr[i]);
        }
 
    }
}
