/** FILE: Generate-Parentheses.c
 * SUBJECT: Generate Parentheses
 *
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 *
 * Example 1:
 *
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 *
 * Input: n = 1
 * Output: ["()"]
 *
 * Constraints:
 *
 * 1 <= n <= 8
 */

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define INITIAL_SIZE 1000

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void	generate(char **result, int *returnSize, char *current, int open, int close, int n)
{
	if (strlen(current) == 2 * n)
	{
		result[*returnSize] = (char *)malloc((2 * n + 1) * sizeof(char));
		strcpy(result[*returnSize], current);
		(*returnSize)++;
		return;
	}

	if (open < n)
	{
		char next[2 * n + 1];
		strcpy(next, current);
		strcat(next, "(");
		generate(result, returnSize, next, open + 1, close, n);
	}

	if (close < open)
	{
		char next[2 * n + 1];
		strcpy(next, current);
		strcat(next, ")");
		generate(result, returnSize, next, open, close + 1, n);
	}
}

char	**generateParenthesis(int n, int *returnSize)
{
	*returnSize = 0;
	int maxCombinations = 1 << (2 * n);
	char **result = (char **)malloc(maxCombinations * sizeof(char *));
	if (result == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}

	char current[2 * n + 1];
	current[0] = '\0';
	generate(result, returnSize, current, 0, 0, n);
	return result;
}
