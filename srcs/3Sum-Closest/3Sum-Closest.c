/**
 * SUBJECT: 3SUM-CLOSEST
 * Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
 *
 * Return the sum of the three integers.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Example 1:
 *
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 * Example 2:
 *
 * Input: nums = [0,0,0], target = 1
 * Output: 0
 * Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 *
 *
 * Constraints:
 *
 * 3 <= nums.length <= 500
 * -1000 <= nums[i] <= 1000
 * -104 <= target <= 104
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * The function `threeSumClosest` finds the closest sum of three integers in an array to a given target
 * value.
 * 
 * @param num The `num` parameter is an integer value that is used in the `abs` function to calculate
 * the absolute value of the input number. The `abs` function returns the absolute value of the input
 * number by checking if it is less than 0 and negating it if necessary.
 * 
 * @return The function `threeSumClosest` is returning an integer value, which is the closest sum of
 * three elements from the input array `nums` to the target value `target`.
 */
int abs(int num)
{
	return num < 0 ? -num : num;
}

int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int threeSumClosest(int *nums, int numsSize, int target)
{
	int closestSum = nums[0] + nums[1] + nums[2];
	qsort(nums, numsSize, sizeof(int), compare);
	
	for (int i = 0; i < numsSize - 2; ++i)
	{
		int k = numsSize - 1;
		int j = i + 1;
		while (j < k)
		{
			int currSum = nums[i] + nums[j] + nums[k];
			if (currSum == target)
				return (currSum);
			if (abs(target - closestSum) > abs(target - currSum))
				closestSum = currSum;
			if (currSum > target)
				--k;
			else
				++j;
		}
	}
	return (closestSum);
}

int main(void)
{
	int vec[] = {-1, 2, 1, -4};
	int n = sizeof(vec) / sizeof(vec[0]);
	printf("Vec: ");
	for (int i = 0; i < n; ++i)
		printf("%d ", vec[i]);
	printf("\n");
	printf("Three sum closest to 1 in above vector is: %d\n", threeSumClosest(vec, n, 1));
	return (0);
}
