/**
 * SUBJECT: WILDCARD-MATCHING
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 *
 *
 *
 * Example 1:
 *
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 * Example 2:
 *
 * Input: s = "aa", p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 *
 * Example 3:
 *
 * Input: s = "cb", p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 *
 *
 * Constraints:
 *
 * 0 <= s.length, p.length <= 2000
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '?' or '*'.
**/

#include <stdio.h>
#include <stdbool.h>

/**
 * The function isMatch checks if a given string matches a pattern containing wildcard characters '*'
 * and '?' in C programming language.
 * 
 * @param s It seems like you have pasted a part of a function that checks if a string `s` matches a
 * pattern `p`. However, you have not provided the value of the string `s`. Could you please provide
 * the value of the string `s` so that I can assist you further with
 * @param p The function `isMatch` you provided is a recursive function that checks if a string `s`
 * matches a pattern `p` where `*` can match any sequence of characters and `?` can match any single
 * character.
 * 
 * @return The function `isMatch` returns a boolean value - `true` if the strings `s` and `p` match
 * based on the wildcard pattern represented by `p`, and `false` otherwise.
**/
bool isMatch(char *s, char *p)
{
	if (*p == '\0')
		return (*s == '\0');
	if (*p == '*')
	{
		while (*(p + 1) == '*')
			p++;
		while (*s != '\0')
		{
			if (isMatch(s, p + 1))
				return true;
			s++;
		}
		return isMatch(s, p + 1);
	}
	else if (*p == '?' || *s == *p)
		return (isMatch(s + 1, p + 1));
	else
		return (false);
}

/**
 *int main(void)
 *{
 *	char test_strings[][20] = {
 *		"aa", "a", "aa", "cb", "ac", "abc", "a*c", "ab*c", "a***bc"};
 *	char test_patterns[][20] = {
 *		"a", "*", "a*", "?a", "a*c", "ab*a", "*?", "*bc", "a***bc"};
 *
 *	int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);
 *	for (int i = 0; i < num_tests; i++)
 *		printf("String: %s, Pattern: %s, Match: %d\n", test_strings[i], test_patterns[i], isMatch(test_strings[i], test_patterns[i]));
 *	return 0;
 *}
**/
