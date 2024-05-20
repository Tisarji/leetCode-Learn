/** FILE: findContentChildren.c
 * Subject: ASSIGN-COOKIES
 * Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
 *
 * Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
 *
 *
 * Example 1:
 *
 * Input: g = [1,2,3], s = [1,1]
 * Output: 1
 * Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
 * And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
 * You need to output 1.
 * Example 2:
 *
 * Input: g = [1,2], s = [1,2,3]
 * Output: 2
 * Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
 * You have 3 cookies and their sizes are big enough to gratify all of the children,
 * You need to output 2.
 *
 *
 * Constraints: -
 *
 * 1 <= g.length <= 3 * 104
 * 0 <= s.length <= 3 * 104
 * 1 <= g[i], s[j] <= 231 - 1
 */

#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int findContentChildren(int *g, int gSize, int *s, int sSize)
{
	qsort(g, gSize, sizeof(int), compare);
	qsort(s, sSize, sizeof(int), compare);

	int i = 0;
	int j = 0;
	int count = 0;

	while (i < gSize && j < sSize)
	{
		if (s[j] >= g[i])
		{
			count++;
			i++;
		}
		j++;
	}
	return (count);
}

int main(int ac, char **av)
{
	int g[] = {1, 2, 3};
	int s[] = {1, 1};
	int gSize = sizeof(g) / sizeof(g[0]);
	int sSize = sizeof(s) / sizeof(s[0]);
	printf("Output for example 1: %d\n", findContentChildren(g, gSize, s, sSize));

	int g2[] = {1, 2};
	int s2[] = {1, 2, 3};
	gSize = sizeof(g2) / sizeof(g2[0]);
	sSize = sizeof(s2) / sizeof(s2[0]);
	printf("Output for example 2: %d\n", findContentChildren(g2, gSize, s2, sSize));

	return (0);
}
