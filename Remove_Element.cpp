/*
 * Problem Description
 *
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 */
 
/*
 * 题意：在一个数组里面移除指定value，并且返回新的数组长度。
 * 解决方案：
 * 使用两个游标i、j遍历数组。如果碰到了value，使用j记录位置，同时递增i，直到下一个非value出现。
 * 将此时i对应的值复制到j的位置上，增加j，重复上述过程直到遍历结束。这时候j就是新的数组长度。
 */

class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int i = 0;
        int j = 0;
        for(i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
