// 4. Median of Two Sorted Arrays
// Hard
// Topics
// Companies
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

#include <stdio.h>
#include <stdlib.h>

double	findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int totalSize = nums1Size + nums2Size;
	int half = totalSize / 2;
	int *merged = malloc(totalSize * sizeof(int));
	int i = 0, j = 0, k = 0;

	while (i < nums1Size && j < nums2Size)
	{
		if (nums1[i] < nums2[j])
			merged[k++] = nums1[i++];
		else
			merged[k++] = nums2[j++];
	}
	while (i < nums1Size)
		merged[k++] = nums1[i++];
	while (j < nums2Size)
		merged[k++] = nums2[j++];
	double median;
	if (totalSize % 2 == 0)
		median = (merged[half - 1] + merged[half]) / 2.0;
	else
		median = merged[half];
	free(merged);
	return median;
}

// int	main(void)
// {
// 	int nums1[] = {1, 3};
// 	int nums2[] = {2};
// 	int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
// 	int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
// 	double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
// 	printf("Median: %.5f\n", median);
// 	return 0;
// }
