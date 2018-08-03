/*
 * Problem Description
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
 * 
 * Input:
 * [
 *    [ 1, 2, 3 ],
 *    [ 4, 5, 6 ],
 *    [ 7, 8, 9 ]
 * ]
 *
 * Output:  [1,2,4,7,5,3,6,8,9]
 */
 
 // test_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
 *    先不考虑方向，统一方向为由上到下，每次都存入到一个向量中。这样每个向量的首个元素为矩阵的上边线及右边线（'^'号标明部分）
 *    共为: m + n - 1 个向量。之后只需要考虑每个'^'的行列号的确定即可！
 *
 *    ^^^^^^^^^^^^^
 *    ************^
 *    ************^
 *    ************^
 *    ************^
 *
 */

std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& matrix)
{
	int m = matrix.size();
	if (m == 0) 
		return std::vector<int>();
	int n = matrix[0].size();

	std::vector<std::vector<int>> tmp(m + n - 1);
	for (int i = 0; i < m + n - 1; i++)
	{
		int row = std::max(0, i - n + 1);
		int col = std::min(i, n - 1);

		for (; col >= 0 && row < m; row++, col--)
		{
			tmp[i].push_back(matrix[row][col]);
		}
	}
	std::vector<int> res;
	for (int i = 0; i < tmp.size(); i++)
	{
		if (i % 2)
			res.insert(res.end(), tmp[i].begin(), tmp[i].end());
		else
			res.insert(res.end(), tmp[i].rbegin(), tmp[i].rend());
	}
	return res;
}
	


int main()
{
	std::vector<std::vector<int>> matrix{ {1,2,3,4}, {5,6,7,8} };
	std::vector<int> res = findDiagonalOrder(matrix);
	for (auto item = res.begin(); item != res.end(); ++item)
	{
		std::cout << *item << " ";
	}
	std::cout << std::endl;
    return 0;
}
