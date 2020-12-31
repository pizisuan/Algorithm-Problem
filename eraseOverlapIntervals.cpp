
/*
 * Problem Description
 * Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 *
 * Example 1
 * Input: [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
 *
 * Example 2
 * Input: [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
 *
 */

// 思路：贪心算法


class Solution_435 
{
    // 435. 无重叠区间
    // 贪心
public:
    struct cmp
    {
        bool operator()(const vector<int>& lhs, const vector<int>& rhs)
        {
            return lhs[1] < rhs[1];
        }
    }cp;

    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if (intervals.empty())
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cp);
        int ori = intervals[0][1];
        int res = 0;
        for(int i = 1; i < intervals.size(); ++i)
        {
            auto& item = intervals[i];
            if (item[0] < ori)
            {
                res += 1;
            }
            else
            {
                ori = item[1];
            }
        }
        return res;
    }
};