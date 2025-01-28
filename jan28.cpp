#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited, int &n, int &m)
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;

        int delRow[4] = {-1, 0, +1, 0};
        int delCol[4] = {0, +1, 0, -1};
        int ans = 0;
        while (!q.empty())
        {
            row = q.front().first;
            col = q.front().second;
            ans += grid[row][col];
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = delRow[i] + row;
                int ncol = delCol[i] + col;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] > 0)
                {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return ans;
    }

public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] > 0 && !visited[i][j])
                {
                    int value = bfs(i, j, grid, visited, n, m);
                    ans = max(ans, value);
                }
            }
        }

        return ans;
    }
};