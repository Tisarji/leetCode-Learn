/** FILE: subset.c
 * SUBJECT: SUBSET
 *
 * Given an integer array nums of unique elements, return all possible
 * subsets
 *  (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in any order.
 *
 *
 * Example 1:
 *
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * Example 2:
 *
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 * Constraints:
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
	int totalSubsets = 1 << numsSize; // 2^numsSize
	*returnSize = totalSubsets;

	int **result = (int **)malloc(totalSubsets * sizeof(int *));
	*returnColumnSizes = (int *)malloc(totalSubsets * sizeof(int));

	for (int i = 0; i < totalSubsets; ++i)
	{
		int subsetSize = 0;
		for (int j = 0; j < numsSize; ++j)
		{
			if (i & (1 << j))
				++subsetSize;
		}
		result[i] = (int *)malloc(subsetSize * sizeof(int));
		(*returnColumnSizes)[i] = subsetSize;
		int index = 0;
		for (int j = 0; j < numsSize; ++j)
		{
			if (i & (1 << j))
				result[i][index++] = nums[j];
		}
	}
	return (result);
}

void printSubsets(int **subsets, int subsetsSize, int *subsetsColumnSizes)
{
	for (int i = 0; i < subsetsSize; ++i)
	{
		printf("[");
		for (int j = 0; j < subsetsColumnSizes[i]; ++j)
		{
			printf("%d", subsets[i][j]);
			if (j < subsetsColumnSizes[i] - 1)
			{
				printf(", ");
			}
		}
		printf("]\n");
	}
}

int main(void)
{
	int nums[] = {1, 2, 3};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int returnSize;
	int *returnColumnSizes;
	int **result = subsets(nums, numsSize, &returnSize, &returnColumnSizes);

	printSubsets(result, returnSize, returnColumnSizes);

	for (int i = 0; i < returnSize; ++i)
		free(result[i]);
	free(result);
	free(returnColumnSizes);
	return (0);
}
