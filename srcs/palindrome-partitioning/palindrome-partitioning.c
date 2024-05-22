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

// Helper function to check if a substring is a palindrome
bool isPalindrome(char *s, int start, int end)
{
	while (start < end)
	{
		if (s[start] != s[end])
		{
			return false;
		}
		start++;
		end--;
	}
	return true;
}

void backtrack(char *s, int start, int len, char ****result, int *returnSize, int **returnColumnSizes, char **currentList, int currentListSize)
{
	if (start == len)
	{
		(*returnSize)++;
		*result = realloc(*result, sizeof(char **) * (*returnSize));
		(*result)[*returnSize - 1] = malloc(sizeof(char *) * currentListSize);
		(*returnColumnSizes) = realloc(*returnColumnSizes, sizeof(int) * (*returnSize));
		(*returnColumnSizes)[*returnSize - 1] = currentListSize;

		for (int i = 0; i < currentListSize; i++)
			(*result)[*returnSize - 1][i] = strdup(currentList[i]);
		return;
	}

	for (int end = start; end < len; end++)
	{
		if (isPalindrome(s, start, end))
		{
			currentList[currentListSize] = strndup(s + start, end - start + 1);
			backtrack(s, end + 1, len, result, returnSize, returnColumnSizes, currentList, currentListSize + 1);
			free(currentList[currentListSize]);
		}
	}
}

char ***partition(char *s, int *returnSize, int **returnColumnSizes)
{
	int len = strlen(s);
	*returnSize = 0;
	*returnColumnSizes = NULL;
	char ***result = NULL;
	char **currentList = malloc(sizeof(char *) * len);

	backtrack(s, 0, len, &result, returnSize, returnColumnSizes, currentList, 0);

	free(currentList);
	return result;
}

int main(void)
{
	char s1[] = "aab";
	int returnSize1;
	int *returnColumnSizes1;
	char ***result1 = partition(s1, &returnSize1, &returnColumnSizes1);

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
