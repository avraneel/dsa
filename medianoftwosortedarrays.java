// Find median of two sorted arrays

class medianoftwosortedarray {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        int n = n1 + n2;
        int A[] = new int[n];
        int i = 0;
        int j = 0;
        int k = 0;
        int shorter = 0;
        double median = 0.0;
        if(n1 == 0) {
            A = nums2;
        }
        else if (n2 == 0) {
            A = nums1;
        }
        else {
            for(k = 0; k < n; k++) {
                if(nums1[i] < nums2[j]) {
                    A[k] = nums1[i];
                    i++;
                }
                else {
                    A[k] = nums2[j];
                    j++;
                }
                if(i == n1) {
                    shorter = 1;
                    break;
                }
                if(j == n2) {
                    shorter = 2;
                    break;
                }
            }
            k++;
            if(shorter == 1)
                while(k < n) {
                    A[k] = nums2[j];
                    j++;
                    k++;
            }
            if(shorter == 2)
                while(k < n) {
                    A[k] = nums1[i];
                    i++;
                    k++;
            }
        }
        for (int x:A) System.out.print(x + " ");
        if(n % 2 == 0) {
            median = A[(n/2) - 1] + A[n/2];
            median /= 2;
        }
        else
            median = A[((n+1)/2) - 1];
        return median;
    }
    
    double findMedian(int A[]) {
        int n = A.length;
        double median = 0.0;
        if(n % 2 == 0) 
            median = (A[(n/2) - 1] + A[n/2])/2;
        else
            median = A[((n+1)/2) - 1];
        return median;
    }
    
}
