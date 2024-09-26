/** FILE: palindrome-partitioning.c
 * SUBJECT: PALINDROM - PARTITIONING
 * Given a string s, partition s such that every substring
 *  of the partition is a
 * palindrome
 * . Return all possible palindrome partitioning of s.
 *
 *
 *
 * Example 1:
 *
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 *
 * Input: s = "a"
 * Output: [["a"]]
 *
 *
 * Constraints:
 *
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// Function to check if a substring is a palindrome
bool isPalindrome(const char *s, int l, int r)
{
	while (l < r)
	{
		if (s[l++] != s[r--])
			return (false);
	}
	return (true);
}

// Recursive function for depth-first search
void dfs(const char *s, int start, int len, char ***path, int *pathSize, int *pathCapacity,
		 char ****ans, int *returnSize, int **returnColumnSizes)
{
	if (start == len)
	{
		(*returnSize)++;
		*ans = realloc(*ans, sizeof(char **) * (*returnSize));
		(*ans)[*returnSize - 1] = malloc(sizeof(char *) * (*pathSize));
		(*returnColumnSizes) = realloc(*returnColumnSizes, sizeof(int) * (*returnSize));
		(*returnColumnSizes)[*returnSize - 1] = *pathSize;

		for (int i = 0; i < *pathSize; i++)
			(*ans)[*returnSize - 1][i] = strdup((*path)[i]);
		return ;
	}

	for (int i = start; i < len; ++i)
	{
		if (isPalindrome(s, start, i))
		{
			if (*pathSize >= *pathCapacity)
			{
				*pathCapacity *= 2;
				*path = realloc(*path, sizeof(char *) * (*pathCapacity));
			}
			(*path)[*pathSize] = strndup(s + start, i - start + 1);
			(*pathSize)++;
			dfs(s, i + 1, len, path, pathSize, pathCapacity, ans, returnSize, returnColumnSizes);
			free((*path)[*pathSize - 1]);
			(*pathSize)--;
		}
	}
}

char ***partition(char *s, int *returnSize, int **returnColumnSizes)
{
	int		len = strlen(s);
	*returnSize = 0;
	*returnColumnSizes = NULL;
	char	***ans = NULL;
	int		pathCapacity = 16;
	char	**path = malloc(sizeof(char *) * pathCapacity);
	int		pathSize = 0;

	dfs(s, 0, len, &path, &pathSize, &pathCapacity, &ans, returnSize, returnColumnSizes);

	free(path);
	return ans;
}
int main(void)
{
	char	s1[] = "aab";
	int		returnSize1;
	int		*returnColumnSizes1;
	char	***result1 = partition(s1, &returnSize1, &returnColumnSizes1);

	printf("Input: %s\nOutput:\n", s1);
	for (int i = 0; i < returnSize1; i++)
	{
		printf("[");
		for (int j = 0; j < returnColumnSizes1[i]; j++)
		{
			printf("\"%s\"", result1[i][j]);
			if (j < returnColumnSizes1[i] - 1)
				printf(", ");
			free(result1[i][j]);
		}
		printf("]\n");
		free(result1[i]);
	}
	free(result1);
	free(returnColumnSizes1);

	return (0);
}
