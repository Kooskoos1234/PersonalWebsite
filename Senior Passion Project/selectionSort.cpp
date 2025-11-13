#include "selectionSort.h"

/*
sorting function for string types (should work for numbers inside of strings
too). this sorts via character ASCII code, so any character before "A" on the
table will be considered before it, and any character after "Z" will be
considered after it. letters will be considered the same if one is uppercase and
the other is lowercase, so they will sort using the following characters. the
characters with ASCII codes higher than 'Z' and lower than 'a' will be
considered higher than both because of the sorting method.
*/
template <> void selectionSort(std::vector<std::string>& array) {
    for (int i = 0; i < array.size(); i++) {
        int temp = (int)array.size() - 1;
        for (int j = i; j < array.size(); j++) {
            if (alphabeticalCompare(array[j], array[temp]) <= 0) {
                temp = j;
            }
        }
        std::swap(array[temp], array[i]);
    }
}
