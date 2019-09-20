/*
 * Problem Description
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 *
 */

// 题意：给定一组木板长度，找到其中的两根，使其能容纳的水量最多。
// 思路：水量取决于两个因素--长度、高度，因此可以采用双指针的思路，先让其位于首尾（保证当前选择的两根木板间长度最大，计算水量），然后收缩两根木板的位置。
// 收缩的条件是：哪个木板长度短，哪个木板往对方木板靠近，在靠近的过程中，遇到某根木板的长度大于先前木板停下来，计算水量。



int maxArea(vector<int>& height) 
{
	// 确定首尾木板位置
	int left_pos = 0;
	int right_pos = height.size() - 1;
	int volumn = 0;
	while (left_pos < right_pos)
	{
		// 计算当前两根木板间的存储水量
		int left_height = height[left_pos];
		int right_height = height[right_pos];
		int water_height = left_height > right_height ? right_height : left_height;
		int water_width = right_pos - left_pos;
		int cur_volumn = water_width * water_height;
		if (cur_volumn > volumn)
		{
			volumn = cur_volumn;
		}

		// 变化木板的位置
		if (left_height < right_height)
		{
			while (++left_pos)
			{
				if (left_pos >= right_pos)
				{
					break;
				}
				if (height[left_pos] > left_height)
				{
					break;
				}
			}
		}
		else
		{
			while (--right_pos)
			{
				if (right_pos <= left_pos)
				{
					break;
				}
				if (height[right_pos] > right_height)
				{
					break;
				}
			}
		}
	}
	return volumn;
}
