#include <bits/stdc++.h>
using namespace std;

// Approach 1 Dynamic Programming

class Solution
{

public:
    int minCost(vector<vector<int>> &grid)
    {
        int numsRows = grid.size();
        int numsCols = grid[0].size();

        vector<vector<int>> minChanges(numsRows, vector<int>(numsCols, INT_MAX));

        // Starting point
        minChanges[0][0] = 0;

        while (true)
        {
            vector<vector<int>> prevState = minChanges;
            for (int row = 0; row < numsRows; row++)
            {
                for (int col = 0; col < numsCols; col++)
                {
                    if (row > 0)
                    {
                        minChanges[row][col] = min(minChanges[row][col], minChanges[row - 1][col] + (grid[row - 1][col] == 3 ? 0 : 1));
                    }

                    if (col > 0)
                    {
                        minChanges[row][col] = min(minChanges[row][col], minChanges[row][col - 1] + (grid[row][col - 1] == 1 ? 0 : 1));
                    }
                }
            }

            for (int row = numsRows - 1; row >= 0; row--)
            {
                for (int col = numsCols - 1; col >= 0; col--)
                {
                    if (row < numsRows - 1)
                    {
                        minChanges[row][col] = min(minChanges[row][col], minChanges[row + 1][col] + (grid[row + 1][col] == 4 ? 0 : 1));
                    }

                    if (col < numsCols - 1)
                    {
                        minChanges[row][col] = min(minChanges[row][col], minChanges[row][col + 1] + (grid[row][col + 1] == 2 ? 0 : 1));
                    }
                }
            }

            if (prevState == minChanges)
            {
                break;
            }
        }

        return minChanges[numsRows - 1][numsCols - 1];
    }
};

// Time Complexity : O(n^2 * m^2)
// Space Complexity : O(n * m)

// Approach 2 Dijkstra's Algorithm
class Solution
{
public:
    // Direction vectors: right, left, down, up (matching grid values 1, 2, 3,
    // 4)
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>> &grid)
    {
        int numRows = grid.size(), numCols = grid[0].size();

        // Min-heap ordered by cost. Each element is {cost, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});

        // Track minimum cost to reach each cell
        vector<vector<int>> minCost(numRows, vector<int>(numCols, INT_MAX));
        minCost[0][0] = 0;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0], row = curr[1], col = curr[2];

            // Skip if we've found a better path to this cell
            if (minCost[row][col] != cost)
                continue;

            // Try all four directions
            for (int dir = 0; dir < 4; dir++)
            {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];

                // Check if new position is valid
                if (newRow >= 0 && newRow < numRows && newCol >= 0 &&
                    newCol < numCols)
                {
                    // Add cost=1 if we need to change direction
                    int newCost = cost + (dir != (grid[row][col] - 1) ? 1 : 0);

                    // Update if we found a better path
                    if (minCost[newRow][newCol] > newCost)
                    {
                        minCost[newRow][newCol] = newCost;
                        pq.push({newCost, newRow, newCol});
                    }
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }
};

// Time Complexity : O(n * m * log(n * m))
// Space Complexity : O(n * m)

// Approach 3 0 - 1 BFS(Using deque)
class Solution
{
public:
    // Direction vectors: right, left, down, up (matching grid values 1, 2, 3,
    // 4)
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>> &grid)
    {
        int numRows = grid.size(), numCols = grid[0].size();

        // Track minimum cost to reach each cell
        vector<vector<int>> minCost(numRows, vector<int>(numCols, INT_MAX));

        // Use deque for 0-1 BFS - add zero cost moves to front, cost=1 to back
        deque<pair<int, int>> deque;
        deque.push_front({0, 0});
        minCost[0][0] = 0;

        while (!deque.empty())
        {
            int row = deque.front().first, col = deque.front().second;
            deque.pop_front();

            // Try all four directions
            for (int dir = 0; dir < 4; dir++)
            {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];
                int cost = (grid[row][col] != (dir + 1)) ? 1 : 0;

                // If position is valid and we found a better path
                if (isValid(newRow, newCol, numRows, numCols) &&
                    minCost[row][col] + cost < minCost[newRow][newCol])
                {
                    minCost[newRow][newCol] = minCost[row][col] + cost;

                    // Add to back if cost=1, front if cost=0
                    if (cost == 1)
                    {
                        deque.push_back({newRow, newCol});
                    }
                    else
                    {
                        deque.push_front({newRow, newCol});
                    }
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }

private:
    // Check if coordinates are within grid bounds
    bool isValid(int row, int col, int numRows, int numCols)
    {
        return row >= 0 && row < numRows && col >= 0 && col < numCols;
    }
};

//Time Complexity : O(n * m)
//Space Complexity : O(n * m)
