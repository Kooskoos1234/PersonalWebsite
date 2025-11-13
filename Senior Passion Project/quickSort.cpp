#include "quickSort.h"

//performs a quickSort operation, where the pivot is the rightmost element; string specialization
template <> int partition<std::string>(std::vector<std::string>& array, int low, int high) {
    int pivot = high; //pivot is rightmost element in subarray
    int i = low - 1; //i is lowest element's index - 1. elements are always swapped with i
    for (int j = low; j < high; j++) { //loop through current subarray
        if (alphabeticalCompare(array[j], array[pivot]) < 0) { //if index j is smaller than pivot's value
            i++; //i is increased by 1
            swap(array, i, j); //swap
        }
    }
    i++;
    swap(array, i, high); //swap pivot with i
    return i; //return endpoint of pivot; this helps determine where the new subarrays start/end
}
