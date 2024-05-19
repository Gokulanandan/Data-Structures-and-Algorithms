package Sorting_Algorithms;

import java.util.Arrays;

public class BubbleSort {
    public static void main(String[] args) {
        int[] arr = {2,9,6,7,3};
        bubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    static void bubbleSort(int[] arr){
        for(int i=0; i<arr.length; i++){
            // Outer loop is just for iterating through the list of elements in the array.
            // It will denote the number of elements that are sorted at a point of time
            for(int j=1; j <= arr.length-1-i; j++){
                // Run the inner loop to iterate through the elements and swap
                if (arr[j] < arr[j-1]) {
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
            }
        }
    }
}

