/*
 * Problem Description
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
 * You may assume all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 * Input:
 *       11110
 *       11010
 *       11000
 *       00000
 * 
 * Output: 1
 *
 *
 * Example 2:
 *
 * Input:
 *       11000
 *       11000
 *       00100
 *       00011
 *
 * Output: 3
 */

// DFS 深度优先搜索
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int res = 0;
        for(int i = 0; i < grid.size(); ++ i)
            for(int j = 0; j < grid[0].size(); ++ j)
                if(grid[i][j] == '1')
                {
                    ++ res;
                    DFS(grid, i, j);
                }
        return res;
    }
private:
    void DFS(vector<vector<char>>& grid, int x, int y)
    {
        grid[x][y] = '0';
        if(x > 0 && grid[x - 1][y] == '1')
            DFS(grid, x - 1, y);
        if(x < grid.size() - 1 && grid[x + 1][y] == '1')
            DFS(grid, x + 1, y);
        if(y > 0 && grid[x][y - 1] == '1')
            DFS(grid, x, y - 1);
        if(y < grid[0].size() - 1 && grid[x][y + 1] == '1')
            DFS(grid, x, y + 1);
    }
};
