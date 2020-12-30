
/*
 * Problem Description
 * We have a collection of stones, each stone has a positive integer weight.
 * Each turn, we choose the two heaviest stones and smash them together.  
 * Suppose the stones have weights x and y with x <= y.  The result of this smash is:
 * If x == y, both stones are totally destroyed;
 * If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
 *
 * At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)
 *
 * Example 1
 * Input: [2,7,4,1,8,1]
 * Output: 1
 *
 */

// 思路：构建最大堆

int lastStoneWeight(vector<int>& stones) 
{
	priority_queue<int>q(stones.begin(), stones.end());
	while (q.size() > 1)
	{
		int first = q.top();
		q.pop();
		int second = q.top();
		q.pop();

		int new_stone = first - second;
		if (new_stone)
		{
			q.push(new_stone);
		}
	}
	if (q.size())
	{
		return q.top();
	}
	return 0;
}