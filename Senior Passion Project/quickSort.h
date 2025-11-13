#ifndef quickSort_H
#define quickSort_H

#include "arrayManipulation.h"

//performs a quickSort operation, where the pivot is the rightmost element
template <typename T> int partition(std::vector<T>& vec, int low, int high) {
    int pivot = high; //pivot is rightmost element in subarray
    int i = low - 1; //i is lowest element's index - 1. elements are always swapped with i
    for (int j = low; j < high; j++) { //loop through current subarray
        if (vec[j] < vec[pivot]) { //if index j is smaller than pivot's value
            i++; //i is increased by 1
            swap(vec, i, j); //swap
        }
    }
    i++;
    swap(vec, i, high); //swap pivot with i
    return i; //return endpoint of pivot; this helps determine where the new subarrays start/end
}

/*
  Quicksort function for numeric types. "low" should be either the lowest index of the array
  you want to sort (0) or the lowest index of the subarray you want to sort. "high" should be
  either the highest index of the array you want to sort *(length - 1)* or the highest index
  of the subarray you want to sort.
*/
template <typename T> void quickSort(std::vector<T>& vec, int low, int high) {
    if (low < high) { //if array is one element long, pass
        int pi = partition(vec, low, high); //equivalent to pivot's endpoint after call

        //every time the partition function is called, this function is called again twice
        //once for the subarray to the left of where the pivot ended up
        //once for the subarray to the right of where the pivot ended up
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}
#endif