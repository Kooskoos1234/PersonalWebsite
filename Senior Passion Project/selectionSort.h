#include "arrayManipulation.h"

#ifndef selectionSort_H
#define selectionSort_H

//selection sort for numberic types (every basic type aside from strings, basically)
//if used for chars, it should work, but will consider "Z" to be smaller than "a"
template <typename T> void selectionSort(std::vector<T>& array) {
    // loop that runs length times
    for (int i = 0; i < array.size(); i++) {
        int temp = (int)array.size() - 1;
        // length -  1; index of the last element in the array.
        // THIS IS WHERE THE FINAL ELEMENT IN SORTING WILL END UP
        for (int j = i; j < array.size(); j++) {
            if (array[j] < array[temp]) {
                temp = j;
                // this turns temp into the index of the smallest element in the section
                // of the array that has already been checked
            }
        }
        std::swap(array[temp], array[i]); // swaps index temp so that it's in correct order
    }
}

#endif