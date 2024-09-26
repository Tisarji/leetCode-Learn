/** File: Sum-of-Square-Numbers
 * SUBJECT: Sum-of-Square-Numbers
 * Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
 * 
 * Example 1:
 * Input: c = 5
 * Output: true
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * Example 2:
 * Input: c = 3
 * Output: false
 *  
 * 
 * Constraints: 0 <= c <= 231 - 1
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool judgeSquareSum(int c)
{
	long long i = 0, j = sqrt(c);
	while (i <= j)
	{
		long long sum = i * i + j * j;
		if (sum == c)
			return true;
		else if (sum < c)
			i++;
		else
			j--;
	}
	return (false);
}
/**
 * int	main(void)
 * {
 * 	int c = 5;
 * 	printf("Output: %s\n", judgeSquareSum(c) ? "true" : "false");
 * 	c = 3;
 * 	printf("Output: %s\n", judgeSquareSum(c) ? "true" : "false");
 * 	return (0);
 * }
**/
