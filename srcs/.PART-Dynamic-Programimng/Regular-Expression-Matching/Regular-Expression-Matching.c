/** FILE: Regular-Expression-Matching.c
 * SUBJECT: Regular Expression Matching
 * Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * Example 2:
 * 
 * Input: s = "aa", p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 * Example 3:
 * 
 * Input: s = "ab", p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *  
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 20
 * 1 <= p.length <= 20
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '.', and '*'.
 * It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool	isMatch(char* s, char* p)
{
	bool	first_match;

	if (*p == '\0')
		return (*s == '\0');
	first_match = ((*s != '\0' && (*s == *p || *p == '.')));
	if (*(p + 1) == '*')
		return ((isMatch(s, p + 2) || (first_match && isMatch(s + 1, p))));
	else
		return (first_match && isMatch(s + 1, p + 1));
}

int	main(void)
{
	char* test_cases_s[] = {"aa", "aa", "ab"};
	char* test_cases_p[] = {"a", "a*", ".*"};
	bool expected_results[] = {false, true, true};
	int num_tests = sizeof(test_cases_s) / sizeof(test_cases_s[0]);

	for (int i = 0; i < num_tests; i++)
	{
		bool result = isMatch(test_cases_s[i], test_cases_p[i]);
		printf("Test case %d: s = \"%s\", p = \"%s\"\n", i + 1, test_cases_s[i], test_cases_p[i]);
		printf("Expected: %s, Got: %s\n", expected_results[i] ? "true" : "false", result ? "true" : "false");
		printf(result == expected_results[i] ? "PASS\n\n" : "FAIL\n\n");
	}
	return (0);
}
