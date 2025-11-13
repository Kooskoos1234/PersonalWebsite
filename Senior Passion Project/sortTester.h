#ifndef sortTester_H
#define sortTester_H

#include <algorithm>
#include <chrono>
#include "arrayManipulation.h"
#include "quickSort.h"
#include "mergeSort.h"
#include "selectionSort.h"
#include "bubbleSort.h"

//tests introsort on a given array, then returns the time it took to run. 
template <typename T> void testIntroSort(std::vector<T>* vec) {
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	std::sort(vec->begin(), vec->end());
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	double countNano = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	if (!check(*vec, 0, vec->size() - 1))
		throw "ARRAY SORTED INCORRECTLY";
	std::cout << "IntroSort completed in " << countNano / 1.0e9 << " seconds!\n";
}

//tests mergesort on a given array, then returns the time it took to run. 
template <typename T> void testMergeSort(std::vector<T>* vec) {
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	mergeSort(*vec, 0, vec->size() - 1);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	double countNano = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	if (!check(*vec, 0, vec->size() - 1))
		throw "ARRAY SORTED INCORRECTLY";
	std::cout << "MergeSort completed in " << countNano / 1.0e9 << " seconds!\n";
}

//tests quicksort on a given array, then returns the time it took to run. 
template <typename T> void testQuickSort(std::vector<T>* vec) {
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	quickSort(*vec, 0, vec->size() - 1);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	double countNano = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	if (!check(*vec, 0, vec->size() - 1))
		throw "ARRAY SORTED INCORRECTLY";
	std::cout << "QuickSort completed in " << countNano / 1.0e9 << " seconds!\n";
}

//tests selection sort on a given array, then returns the time it took to run.
template <typename T> void testSelectionSort(std::vector<T>* vec) {
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	selectionSort(*vec);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	double countNano = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	if (!check(*vec, 0, vec->size() - 1))
		throw "ARRAY SORTED INCORRECTLY";
	std::cout << "Selection Sort completed in " << countNano / 1.0e9 << " seconds!\n";
}

//tests bubble sort on a given array, then returns the time it took to run.
template <typename T> void testBubbleSort(std::vector<T>* vec) {
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	bubbleSort(*vec);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	double countNano = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	if (!check(*vec, 0, vec->size() - 1))
		throw "ARRAY SORTED INCORRECTLY";
	std::cout << "Bubble Sort completed in " << countNano / 1.0e9 << " seconds!\n";
}

#endif