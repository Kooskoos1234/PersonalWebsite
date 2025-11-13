#ifndef mergeSort_H
#define mergeSort_H

#include <vector>
#include <string>
#include "arrayManipulation.h"

//merges two given subarrays of vec, with left, mid, and right being the separators of the subarrays such that they form two sets, [left, mid] and [mid + 1, right]
template <typename T> void merge(std::vector<T>& vec, int left, int mid, int right)
{
	//get the lengths of the left and right subarrays
	int n1 = mid - left + 1;
	int n2 = right - mid;

	//create temporary vectors for the subarrays, and copy the subarrays into them
	std::vector<T> L(n1), R(n2);
	for (int i = 0; i < n1; i++)
		L[i] = vec[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = vec[mid + i + 1];
	int i = 0, j = 0;
	int k = left;

	//set each element of vec on [left, right - 1] to the lowest element in the two subarrays, assuming that the subarrays are already sorted. 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			vec[k] = L[i];
			i++;
		}
		else
		{
			vec[k] = R[j];
			j++;
		}
		k++;
	}

	//move the remaining elements of the left subarray if any remain
	while (i < n1)
	{
		vec[k] = L[i];
		i++; 
		k++;
	}
	//move the remaining elements of the right subarray if any remain
	while (j < n2)
	{
		vec[k] = R[j];
		j++;
		k++;
	}
}

//uses mergeSort on a given array or subarray from index left to index right
template <typename T> void mergeSort(std::vector<T>& vec, int left, int right)
{
	//if the subarray has a length of 1 or less, return
	if (left >= right)
		return;
	
	//find the middle point between the two endpoints
	int mid = left + (right - left) / 2;
	mergeSort(vec, left, mid);
	mergeSort(vec, mid + 1, right);
	merge(vec, left, mid, right);
}

#endif