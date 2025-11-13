#ifndef arrayManipulation_H
#define arrayManipulation_H

#include <cmath>
#include <iostream>
#include <string_view>
#include <vector>
#include <array>
#include <string_view>

//random number generator for floating point types. 
template <typename T> inline T fRand(T min, T max, int decimalPlaces) {
    T l = (double)rand() / RAND_MAX;
    return round(pow(10, decimalPlaces) * (min + l * (max - min))) / pow(10, decimalPlaces);
}

//creates problems for me to fix (aka an array to sort). use srand() with a seed for proper randomization. produces an integer array.
template <typename T> std::vector<T> createArray(int length, T numMin, T numMax) {
    std::vector<T> vector;
    vector.reserve(length);
    for (int i = 0; i < length; i++) {
        vector.push_back(numMin + rand() % (numMax - numMin + 1));
    }
    vector.shrink_to_fit();
    return vector;
}
//creates problems for me to fix (aka an array to sort). use srand() with a seed for proper randomization. produces a decimal array. 
template <typename T> std::vector<T> createArray(int length, T numMin, T numMax, int decimalPlaces) {
    std::vector<T> vector;
    vector.reserve(length);
    for (int i = 0; i < length; i++) {
        vector.push_back(fRand(numMin, numMax, decimalPlaces));
    }
    vector.shrink_to_fit();
    return vector;
}
//creates problems for me to fix (aka an array to sort). use srand() with a seed for proper randomization. produces a boolean array. 
bool* createArray(int length);
//creates problems for me to fix (aka an array to sort). use srand() with a seed for proper randomization. produces a string array.
std::string* createArray(int length, int wordLength);

//creates problems for me to fix (aka an array to sort). use srand() with a seed for proper randomization. produces an integer array.
template <typename T> std::vector<T> createVector(int length, T numMin, T numMax) {
    std::vector<T> vec;
    vec.reserve(length);
    for (int i = 0; i < length; i++) {
        vec[i] = numMin + rand() % (numMax - numMin + 1);
    }
    vec.shrink_to_fit();
    return vec;
}

//Compares characters by ASCII code. Considers both upper and lowercase letters to be uppercase.
int alphabeticalCompare(const std::string& first, const std::string& second);

//checks if the array is sorted, lowest -> highest, left -> right, between *low* and *high*
template <typename T> bool check(T array[], size_t low, size_t high) {
    for (int i = low; i < high; i++)
    {
        if (!(array[i] <= array[i + 1])) {
            return false;
        }
    }
    return true;
}

//checks if the array is sorted, lowest -> highest, left -> right, between *low* and *high*
template <typename T> bool check(std::vector<T>& vec, size_t low, size_t high) {
    for (int i = low; i < high; i++)
    {
        if (!(vec[i] <= vec[i + 1])) {
            return false;
        }
    }
    return true;
}

//swaps the elements of index1 and index2
template <typename T> void swap(T array[], int index1, int index2) {
    T temp;
    temp = array[index2];
    array[index2] = array[index1];
    array[index1] = temp;
}
//swaps the elements of index1 and index2
template <typename T> void swap(std::vector<T>& array, int index1, int index2) {
    T temp = array[index2];
    array[index2] = array[index1];
    array[index1] = temp;
}

//prints the elements of the array, first to last
template <typename T> void printArray(T array[], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        std::cout << std::boolalpha << array[i];
        if (i != arrayLength - 1) {
            std::cout << ", ";
        }
        else {
            std::cout << ".\n\n";
        }
    }
}
//prints the elements of the array, first to last
template <typename T> void printArray(std::vector<T>& array) {
    for (int i = 0; i < array.size(); i++) {
        std::cout << std::boolalpha << array[i];
        if (i != array.size() - 1) {
            std::cout << ", ";
        }
        else {
            std::cout << ".\n\n";
        }
    }
}

#endif