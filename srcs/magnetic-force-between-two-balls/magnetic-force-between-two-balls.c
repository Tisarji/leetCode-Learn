/** File: magnetic-force-between-two-balls.c
 * SUBJECT: Magnetic Force Between Two Balls
 *
 * In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that
 * the minimum magnetic force between any two balls is maximum.
 * Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
 * Given the integer array position and the integer m. Return the required force.
 *
 *
 *
 * Example 1:
 *
 * Input: position = [1,2,3,4,7], m = 3
 * Output: 3
 * Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
 * Example 2:
 *
 * Input: position = [5,4,3,2,1,1000000000], m = 2
 * Output: 999999999
 * Explanation: We can use baskets 1 and 1000000000.
 *
 *
 * Constraints:
 *
 * n == position.length
 * 2 <= n <= 105
 * 1 <= position[i] <= 109
 * All integers in position are distinct.
 * 2 <= m <= position.length
 *
 */

#include <stdio.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int maxDistance(int *position, int positionSize, int m)
{
	qsort(position, positionSize, sizeof(int), cmp);
	int left = 1, right = 1e9;
	if (m == 2)
		return position[positionSize - 1] - position[0];
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		int balls = 1, prev = position[0];

		for (int i = 1; i < positionSize; i++)
		{
			if (position[i] - prev >= mid)
			{
				balls++;
				prev = position[i];
			}
		}
		if (balls >= m)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (left - 1);
}

int main(void)
{
	int position[] = {1, 2, 3, 4, 7};
	int positionSize = 5;
	int m = 3;
	printf("Output: %d\n", maxDistance(position, positionSize, m));
	int position2[] = {5, 4, 3, 2, 1, 1000000000};
	int positionSize2 = 6;
	int m2 = 2;
	printf("Output: %d\n", maxDistance(position2, positionSize2, m2));
	return (0);
}
