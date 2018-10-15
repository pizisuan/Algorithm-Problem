/*
 * Problem Description
 * Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to
 * wait until a warmer temperature.  If there is no future day for which this is possible, put 0 instead.
 *
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 *
 */

// 我的代码第一版：遍历（耗时长）
// 37 test cases passed. Runtime: 1552 ms


class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& T) 
	  {
        if (T.empty())
        {
            return {};
        }
        vector<int> res;
        for(size_t i = 0; i < T.size(); ++i)
        {
            bool find = false;
            for(size_t j = i+1; j < T.size(); ++j)
            {
                if (T[j] > T[i])
                {
                    find = true;
                    res.push_back(j-i);
                    break;
                }
            }
            if (!find)
            {
                res.push_back(0);
            }
        }
        return res;
    }
};

// 大神的代码
vector<int> dailyTemperatures(vector<int>& temperatures) 
{
    vector<int> res(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; --i) 
	{
        int j = i+1;
        while (j < temperatures.size() && temperatures[j] <= temperatures[i]) 
		{
            if (res[j] > 0) 
				j = res[j] + j;
            else 
				j = temperatures.size();
        }
        // either j == size || temperatures[j] > temperatures[i]
        if (j < temperatures.size()) 
			res[i] = j - i;
    }
    return res;
}
