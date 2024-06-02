package Sorting_Algorithms;

import java.util.Arrays;

public class QuickSort {
    public static void main(String[] args) {
        int[] arr= {5,2,9,4,6,8,7,1,3,0};
        quicksort(arr, 0, arr.length-1);
        System.out.println(arr.length-1);
        System.out.println(Arrays.toString(arr));
    }
    static void quicksort(int[] arr, int low, int hi){
        if(low >= hi) {
            return;
        }
        int start = low;
        int end = hi;
        int mid = start + (end - start)/2;
        int pivot = arr[mid];
        while(start <= end){
            while(arr[start] < pivot){
                start++;
            }
            while(arr[end] > pivot){
                end--;
            }

            if(start <= end){
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;
            }
        }
        quicksort(arr, low, end);
        quicksort(arr, start, hi);
    }
}
