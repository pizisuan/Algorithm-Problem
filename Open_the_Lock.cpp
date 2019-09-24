/*
 * Problem Description
 * You have a lock in front of you with 4 circular wheels. 
 * Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 
 * The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. 
 * Each move consists of turning one wheel one slot.
 *
 * The lock initially starts at '0000', a string representing the state of the 4 wheels.
 * You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
 * Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
 *
 * Example 1
 * Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
 * Output: 6
 * Explanation:
 * A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
 * Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
 * because the wheels of the lock become stuck after the display becomes the dead end "0102".
 *
 * Example 2
 * Input: deadends = ["8888"], target = "0009"
 * Output: 1
 * Explanation:
 * We can turn the last wheel in reverse to move from "0000" -> "0009".
 *
 * Example 3
 * Input: deadends = ["0000"], target = "8888"
 * Output: -1
 */

// 题意：4道轮子锁，给出"0000"到给定开锁的序列最小步数（条件是不能出现给定的死锁序列）
// 思路：采用广度优先搜索算法--利用队列数据结构


int openLock(vector<string>& deadends, string target)
{
	set<string> dead(deadends.begin(), deadends.end());
	if (dead.count("0000"))
		return -1;
	if (target == "0000")
		return 0;
	set<string> check;
	queue<string> q;
	q.push("0000");
	for (int step = 1; !q.empty(); step++)
	{
		for (int n = q.size(); n > 0; n--)
		{
			string cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				for (int dif = 1; dif <= 9; dif += 8)
				{
					string s = cur;
					s[i] = (s[i] - '0' + dif) % 10 + '0';
					if (s == target)
						return step;
					if (!dead.count(s) && !check.count(s))
						q.push(s);
					check.insert(s);
				}
			}
		}
	}
	return -1;
}
