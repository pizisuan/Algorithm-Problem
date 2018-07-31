/*
 *
 *
 *
 */




class Solution 
{
public:
    int pivotIndex(vector<int>& nums) 
    {
        //获取向量总和
        int sum = 0, left_sum = 0;
        for (int item : nums)
        {
            sum += item;
        }
        //找位置
        for (int index = 0; index < nums.size(); index++)
        {
            if (left_sum == sum - left_sum - nums[index])
            {
                return index;
            }
            left_sum += nums[index];
        }
        return -1;
    }
};
