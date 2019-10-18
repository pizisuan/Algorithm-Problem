/*
 * Problem Description
 * On an 8x8 chessboard, there can be multiple Black Queens and one White King.
 *
 * Given an array of integer coordinates queens that represents the positions of the Black Queens.
 * and a pair of coordinates king that represent the position of the White King,
 * return the coordinates of all the queens (in any order) that can attack the King.
 *
 *
 * Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
 * Output: [[0,1],[1,0],[3,3]]
 *
 */

// 题意：国际象棋中给定"皇帝"位置，找到能够攻击"皇帝"的皇后的所有位置
// 思路：分8个方向选取距离"皇帝"最近的那个"皇后"


vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king)
{
	vector<vector<int>> res;
	map<string, vector<int>> final_queens;
	int top, bottom, left, right, left_top, right_top, left_bottom, right_bottom ;
	int king_row = king[0], king_column = king[1];

	for (const auto& queen : queens)
	{
		int queen_row = queen[0], queen_column = queen[1];

		if (queen_row < king_row && queen_column == king_column)
		{
			// up
			if (final_queens.find("up") != final_queens.end())
			{
				if (queen_row > final_queens["up"][0])
				{
					final_queens["up"] = queen;
				}
			}
			else
			{
				final_queens["up"] = queen;
			}
			continue;
		}

		if (queen_row > king_row && queen_column == king_column)
		{
			// down
			if (final_queens.find("down") != final_queens.end())
			{
				if (queen_row < final_queens["down"][0])
				{
					final_queens["down"] = queen;
				}
			}
			else
			{
				final_queens["down"] = queen;
			}
			continue;
		}

		if (queen_row == king_row && queen_column < king_column)
		{
			// left
			if (final_queens.find("left") != final_queens.end())
			{
				if (queen_column > final_queens["left"][1])
				{
					final_queens["left"] = queen;
				}
			}
			else
			{
				final_queens["left"] = queen;
			}
			continue;
		}

		if (queen_row == king_row && queen_column > king_column)
		{
			// right
			if (final_queens.find("right") != final_queens.end())
			{
				if (queen_column < final_queens["right"][1])
				{
					final_queens["right"] = queen;
				}
			}
			else
			{
				final_queens["right"] = queen;
			}
			continue;
		}

		if (queen_row < king_row && queen_column < king_column && king_row - queen_row == king_column - queen_column)
		{
			// left_up
			if (final_queens.find("left_up") != final_queens.end())
			{
				if (queen_row > final_queens["left_up"][0])
				{
					final_queens["left_up"] = queen;
				}
			}
			else
			{
				final_queens["left_up"] = queen;
			}
			continue;
		}

		if (queen_row > king_row && queen_column < king_column && king_row - queen_row == queen_column - king_column)
		{
			// left_down
			if (final_queens.find("left_down") != final_queens.end())
			{
				if (queen_row < final_queens["left_down"][0])
				{
					final_queens["left_down"] = queen;
				}
			}
			else
			{
				final_queens["left_down"] = queen;
			}
			continue;
		}

		if (queen_row < king_row && queen_column > king_column && king_row - queen_row == queen_column - king_column)
		{
			// right_up
			if (final_queens.find("right_up") != final_queens.end())
			{
				if (queen_row > final_queens["right_up"][0])
				{
					final_queens["right_up"] = queen;
				}
			}
			else
			{
				final_queens["right_up"] = queen;
			}
			continue;
		}

		if (queen_row > king_row && queen_column > king_column && king_row - queen_row == king_column - queen_column)
		{
			// right_down
			if (final_queens.find("right_down") != final_queens.end())
			{
				if (queen_row < final_queens["right_down"][0])
				{
					final_queens["right_down"] = queen;
				}
			}
			else
			{
				final_queens["right_down"] = queen;
			}
			continue;
		}
	}

	map<string, vector<int>>::iterator iter = final_queens.begin();
	while (iter != final_queens.end())
	{
		res.push_back(iter->second);
		iter++;
	}
	return res;
}