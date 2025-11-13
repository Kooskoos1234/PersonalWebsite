#include <cmath>
#include <string>
#include "arrayManipulation.h"

std::string* createArray(int length, int wordLength) {
    std::string* array = new std::string[length];
    for (int i = 0; i < length; i++) {
        char* word = new char[wordLength + 1];
        word[0] = (rand() % 26) + 65;
        for (int j = 0; j < wordLength; j++) {
            word[j] = (rand() % 26) + 97;
            if ((rand() % 2)) {
                word[j] = toupper(word[j]);
            }
        }
        const std::string temp = word;
        delete[] word;
        array[i] = temp;
    }
    return array;
}

bool* createArray(int length) {
    bool* array = new bool[length];
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 2;
    }
    return array;
}

int alphabeticalCompare(const std::string& first, const std::string& second) {
    for (int i = 0; i < first.length(); i++) {
        if (std::toupper(first[i]) != std::toupper(second[i])) {
            return std::toupper(first[i]) - std::toupper(second[i]);
        }
    }
    return -1;
}

//check specialization for strings
template <> bool check(std::string array[], size_t low, size_t high) {
    for (int i = low; i < high; i++)
    {
        if (!(alphabeticalCompare(array[i], array[i + 1]) <= 0)) {
            return false;
        }
    }
    return true;
}

//check specialization for strings
template <> bool check(std::vector<std::string>& vec, size_t low, size_t high) {
    for (int i = low; i < high; i++)
    {
        if (!(alphabeticalCompare(vec[i], vec[i + 1]) <= 0)) {
            return false;
        }
    }
    return true;
}