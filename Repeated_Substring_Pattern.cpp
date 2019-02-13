/*
 * Problem Description
 * Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring 
 * together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
 *
 * Example 1:
 * Input: "abab"
 * Output: True
 * Explanation: It's the substring "ab" twice.
 *
 * Example 2:
 * Input: "aba"
 * Output: False
 * Explanation: It's the substring "ab" twice.
 *
 */
 
 // 思路：将右边字符串+左边字符串 与 原始字符串做比较，如果相同：则为True
 
class Solution 
{
public:
	bool repeatedSubstringPattern(string s) 
	{
		int size = s.length();
		if (size < 2)
			return false;
		for (int i = 1; i <= size/2; ++i)
		{
			if (size % i == 0)
			{
				string left_str = s.substr(0, i);
				string right_str = s.substr(i);
				if (right_str + left_str == s)
					return true;
			}
		}
		return false;
	}
};
