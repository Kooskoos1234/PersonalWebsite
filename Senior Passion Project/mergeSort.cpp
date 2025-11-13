#include "mergeSort.h"

//merges two given subarrays of vec, with left, mid, and right being the separators of the subarrays such that they form two sets, [left, mid] and [mid + 1, right]
template <> void merge<std::string>(std::vector<std::string>& vec, int left, int mid, int right)
{
	//get the lengths of the left and right subarrays
	int n1 = mid - left + 1;
	int n2 = right - mid;

	//create temporary vectors for the subarrays, and copy the subarrays into them
	std::vector<std::string> L(n1), R(n2);
	for (int i = 0; i < n1; i++)
		L[i] = vec[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = vec[mid + i + 1];
	int i = 0, j = 0;
	int k = left;

	//set each element of vec on [left, right - 1] to the lowest element in the two subarrays, assuming that the subarrays are already sorted. 
	while (i < n1 && j < n2)
	{
		if (alphabeticalCompare(L[i], R[j]) < 0)
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