/** FILE: Longest-Palindromic-Substring.c
 * SUBJECT: Longest Palindromic Substring
 * Medium
 * Topics
 * Companies
 * Hint
 * Given a string s, return the longest 
 * palindromic
 *  
 * substring
 *  in s.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * Example 2:
 * 
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	expand_around_center(char *str, int left, int right)
{
	while (left >= 0 && right < strlen(str) && str[left] == str[right])
	{
		left--;
		right++;
	}
	return (right - left - 1);
}

char	*longestPalindrome(char *str)
{
	int	start;
	int	end;
	int	len_left;
	int	len_right;
	int len;

	start = 0;
	end = 0;
	if (str == NULL || strlen(str) < 1)
		return ("");
	for (int i = 0; i < strlen(str); i++)
	{
		len_left = expand_around_center(str, i, i);
		len_right = expand_around_center(str, i, i + 1);
		if (len_left > len_right)
			len = len_left;
		else
			len = len_right;
		if (len > end - start)
		{
			start = i - (len - 1) / 2;
			end = i + len / 2;
		}
	}
	int pal_lenght = end - start + 1;
	char *result = (char *)malloc((pal_lenght + 1) * sizeof(char));
	strncpy(result, str + start, pal_lenght);
	result[pal_lenght] = '\0';

	return (result);
}

int	main(void)
{
	char s1[] = "babad";
	char s2[] = "cbbd";

	printf("Longest palindromic substring of %s is %s\n", s1, longestPalindrome(s1));
	printf("Longest palindromic substring of %s is %s\n", s2, longestPalindrome(s2));
	return (0);
}
