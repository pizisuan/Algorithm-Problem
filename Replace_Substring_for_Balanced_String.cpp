/*
 * Problem Description
 * You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.
 * A string is said to be balanced if each of its characters appears n/4 times where n is the length of the string.
 * Return the minimum length of the substring that can be replaced with any other string of the same length to make the original string s balanced.
 * Return 0 if the string is already balanced.
 *
 * Example 1:
 * Input: s = "QWER"
 * Output: 0
 * Explanation: s is already balanced.
 *
 * Example 2:
 * Input: s = "QQQW"
 * Output: 2
 * Explanation: We can replace the first "QQ" to "ER".
 */


// 题意：找到长度最小的子串，使得通过变换，让整个长串平衡
// 思路：滑动窗口算法


// 自己的代码
// 找到长度大于 n / 4 的字母及其超出范围的个数。将问题转化为找到原串中的子串，该子串满足两个条件：1.至少包含超出的字母及其超出的个数 2. 满足的子串中选择长度最小

int balancedString(string s)
{
	int freq = s.size() / 4;
	unordered_map<char, int> map;    // 记录原始长串中包含的字母及其个数
	for (char var : s)
		map[var]++;
	unordered_map<char, int>::iterator iter = map.begin();
	unordered_map<char, int> judge_map;    // 记录长度大于n/4的字母及其超出的个数
	while (iter != map.end())
	{
		if (iter->second - freq > 0)
			judge_map[iter->first] = iter->second - freq;
		iter++;
	}

    // 长串本身就平衡
	if (judge_map.empty())
		return 0;

    // 滑动窗口算法
	int start_pos = 0, end_pos = 0;
	int cnt = judge_map.size();
	int res = s.size();
	while (end_pos < s.size())
	{
		if (judge_map.find(s[end_pos]) != judge_map.end())
		{
			judge_map[s[end_pos]]--;
			if (judge_map[s[end_pos]] == 0)
				cnt--;
		}
		++end_pos;
		while (cnt == 0)
		{
			if (judge_map.find(s[start_pos])!=judge_map.end())
			{
				judge_map[s[start_pos]]++;
				if (judge_map[s[start_pos]] > 0)
					cnt++;
			}
			res = min(res, end_pos - start_pos);     // 时刻更新满足条件的子串长度最小值
			++start_pos;
		}
	}
	return res;
}


// 反思：上面自己的代码中的子串的满足的2个条件（应用于滑动窗口算法），其实该题完全没有必要用这两个条件，走了弯路。
// 只需要保证窗口滑动过程中，剩余部分的包含的字母长度满足小于n/4就可以了。
// 因为只要原串除去窗口部分剩余的满足各个字母小于n/4，则该窗口的子串一定就是要的子串之一（因为可以通过替换窗口中的字符使其原串满足条件）

// 大神的代码
int balancedString(string s)
{
    unordered_map<int, int> count;
    int n = s.length(), res = n, i = 0;
    for (int j = 0; j < n; ++j)
    {
        count[s[j]]++;
    }
    for (int j = 0; j < n; ++j)
    {
        count[s[j]]--;
        while (i < n && count['Q'] <= n / 4 && count['W'] <= n / 4 && count['E'] <= n / 4 && count['R'] <= n / 4)
        {
            res = min(res, j - i + 1);
            count[s[i++]] += 1;
        }
    }
    return res;
}