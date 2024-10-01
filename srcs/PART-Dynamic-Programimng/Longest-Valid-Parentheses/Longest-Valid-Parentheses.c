/** FILE: Longest-Valid-Parentheses.c
 * SUBJECT: Longest Valid Parentheses
 *
 * Given a string containing just the characters '(' and ')', return the length of the longest valid
 * (well-formed) parentheses substring.
 *
 * Example 1:
 *
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 * Example 2:
 *
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 * Example 3:
 *
 * Input: s = ""
 * Output: 0
 *
 *
 * Constraints:
 *
 * 0 <= s.length <= 3 * 104
 * s[i] is '(', or ')'.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int longestValidParentheses(char *s)
{
	int maxLen = 0;
	int n = strlen(s);
	int *stack = (int *)malloc((n + 1) * sizeof(int));
	int top = -1;

	stack[++top] = -1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			stack[++top] = i;
		else
		{
			top--;
			if (top == -1)
				stack[++top] = i;
			else
			{
				int currentLen = i - stack[top];
				if (currentLen > maxLen)
					maxLen = currentLen;
			}
		}
	}
	free(stack);
	return (maxLen);
}
