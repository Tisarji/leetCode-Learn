/** FILE: sqrt.c
 * SUBJECT: Sqrt(x)
 * 
 * Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
 * 
 * You must not use any built-in exponent function or operator.
 * 
 * For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 *  
 * 
 * Example 1:
 * 
 * Input: x = 4
 * Output: 2
 * Explanation: The square root of 4 is 2, so we return 2.
 * Example 2:
 * 
 * Input: x = 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 *  
 * 
 * Constraints: 0 <= x <= 231 - 1
 *
 */

int mySqrt(int x)
{
	if (x < 2)
		return (x);

	int left = 1;
	int right = x;
	int result = 0;
	int	mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (mid <= x / mid)
		{
			result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	return (result);
}
