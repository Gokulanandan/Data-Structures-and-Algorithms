package Sorting_Algorithms;

import java.util.Arrays;

public class SelectionSort {
    public static void main(String[] args) {
        int[] arr = {6,4,5,8,1};
        selection_Sort(arr);
        System.out.println(Arrays.toString(arr));
    }

     static int findLargest(int[] arr,int start,int end){
        int max = start;
        for(int i=start;i<=end;i++){
            if(arr[i] > arr[max]) {
                max = i;
            }
        }
        return max;
    }
    static void selection_Sort(int[] arr){
        for(int i=0;i<arr.length;i++) {
            int last = arr.length -1 -i;
            int max = findLargest(arr,0,last);
            if(max != last) {
                int temp = arr[last];
                arr[last] = arr[max];
                arr[max] = temp;
            }
        }
    }
}


