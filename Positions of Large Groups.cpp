

/*
 * Problem Description
 * In a string s of lowercase letters, these letters form consecutive groups of the same character.
 * For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".
 * A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].
 * A group is considered large if it has 3 or more characters.
 * Return the intervals of every large group sorted in increasing order by start index.
 *
 * Example 1
 * Input: s = "abbxxxxzzy"
 * Output: [[3,6]]
 * Explanation: "xxxx" is the only large group with start index 3 and end index 6.
 *
 * Example 2
 * Input: s = "abc"
 * Output: []
 * Explanation: We have groups "a", "b", and "c", none of which are large groups.
 *
 *
 */


vector<vector<int>> largeGroupPositions(string s) 
{
	vector<vector<int>> res;
	int length = static_cast<int>(s.length());
	int start = 0;
	char cur = s[0];
	for (int i = 1; i < length; ++i)
	{
		if(s[i] != cur)
		{
			if (i - start >= 3)
			{
				res.push_back({ start,i - 1 });
			}
			start = i;
			cur = s[i];
		}
	}
	if (length - start >= 3)
	{
		res.push_back({ start,length - 1 });
	}
	return res;
}