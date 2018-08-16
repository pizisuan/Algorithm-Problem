/*
 * Problem Description
 *
 * Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. 
 * If there isn't one, return 0 instead.
 *
 * Example 1:
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 *
 * Explanation:
 * the subarray [4,3] has the minimal length under the problem constraint.
 * 
 */
 
int minSubArrayLen(int s, vector<int>& nums)
{
    int sum = 0, start = 0, n = nums.size(), minlen = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        while (sum >= s)
        {
            minlen = min(minlen, i - start + 1);
            sum -= nums[start++];
        }
    }
    return minlen == INT_MAX ? 0 : minlen;
}
