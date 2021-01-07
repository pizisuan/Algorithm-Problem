/*
 * Problem Description
 * There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
 * A province is a group of directly or indirectly connected cities and no other cities outside of the group.
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
 * Return the total number of provinces.
 *
 *
 * Example 1
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 *
 * Example 2
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 *
 *
 */

// 思路：广度优先搜索

int findCircleNum(vector<vector<int>>& isConnected) 
{
	unordered_set<int> hash_set;
	int cities = isConnected.size();
	int num = 0;
	for (int i = 0; i < cities; i++)
	{
		if (!hash_set.count(i))
		{
			
			num += 1;
			hash_set.insert(i);
			queue<int> q;
			q.push(i);
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				vector<int>& neighbor = isConnected[cur];
				for (int j = 0; j < cities; ++j)
				{
					if (isConnected[cur][j] && !hash_set.count(j))
					{
						q.push(j);
						hash_set.insert(j);
					}
				}
			}

		}
	}
	return num;
}