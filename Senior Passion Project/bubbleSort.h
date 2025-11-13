#include "arrayManipulation.h"

#ifndef bubbleSort_H
#define bubbleSort_H


// I hate bubble sort, here it is, in its full glory, the world-famed flow control + one statement sorting algorithm
//(for(int i=0;i<length;i++){for(int j=0;j<length-i-1;j++){if(array[j]>array[j+1]){swap(array[j], array[j+1])}}})
//with a few lines to make it slightlyless awful
template <typename T> void bubbleSort(std::vector<T>& array) {
    for (int i = 0; i < array.size(); i++) {
        bool swapped = false;
        for (int j = 0; j < array.size() - (i + 1); j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}
#endif