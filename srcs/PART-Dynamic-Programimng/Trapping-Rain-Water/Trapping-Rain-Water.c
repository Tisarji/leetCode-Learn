/** FILE: Trapping-Rain-Water.c
 * SUBJECT: Trapping Rain Water
 *
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 *
 * Example 1:
 *
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
 * Example 2:
 *
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *
 * Constraints:
 *
 * n == height.length
 * 1 <= n <= 2 * 104
 * 0 <= height[i] <= 105
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int trap(int *height, int heightSize)
{
	int left;
	int right;
	int left_max;
	int right_max;
	int water_trapped;

	left = 0;
	right = heightSize - 1;
	left_max = 0;
	right_max = 0;
	water_trapped = 0;
	if (heightSize == 0)
		return (0);
	while (left <= right)
	{
		if (height[left] <= height[right])
		{
			if (height[left] >= height[right])
				left_max = height[left];
			else
				water_trapped += left_max - height[left];
			left++;
		}
		else
		{
			if (height[right] >= right_max)
				right_max = height[right];
			else
				water_trapped += right_max - height[right];
			right--;
		}
	}
	return (water_trapped);
}
