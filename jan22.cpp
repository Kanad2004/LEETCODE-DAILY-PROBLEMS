#include <bits/stdc++.h>
using namespace std;

// Approach 1 (BFS)
// Algorithm
// Define two arrays of size 4: dx = [0, 0, 1, -1] and dy = [1, -1, 0, 0]. Each pair (dx[d], dy[d]) represents one of the four possible directions to an adjacent cell.
// Initialize a 2D matrix, named cellHeights, of the same dimension as isWater. Set all of its cells to an invalid value, i.e. -1.
// Initialize an empty queue of pairs, cellQueue.
// Iterate over the isWater matrix:
// Push every water cell into the cellQueue.
// Set the height of each water cell to be 0.
// Initialize heightOfNextLayer to 1 - that is the height of the neighbors of the cells currently in queue.
// While the cellQueue is not empty:
// Set layerSize to the size of the queue.
// For each cell in the current layer, i.e. for i from 0 to layerSize - 1:
// Pop the top cell currentCell out of the queue.
// For each direction, i.e. for d from 0 to 3:
// Find the neighbor of the current cell to that direction, neighborCell = (currentCell.x + dx[d], currentCell.y + dy[d]).
// If neighbor is a valid cell (i.e. it is not out of the bounds of the matrix) and it is not already visited (i.e. cellHeights[neighbor.x][neighbor.y] == -1):
// Set cellHeights[neighbor.x][neighbor.y] to heightOfNextLayer.
// Push neighbor into the cellQueue.
// Increment heightOfNextLayer by 1.
// Return cellHeights.
class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int n = isWater.size();
        int m = isWater[0].size();

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        vector<vector<int>> cellHeights(n, vector<int>(m, -1));

        queue<pair<int, int>> cellQueue;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isWater[i][j] == 1)
                {
                    cellQueue.push({i, j});
                    cellHeights[i][j] = 0;
                }
            }
        }

        int heightOfNextLayer = 1;

        while (!cellQueue.empty())
        {
            int layerSize = cellQueue.size();
            for (int i = 0; i < layerSize; i++)
            {
                auto currentCell = cellQueue.front();
                cellQueue.pop();

                for (int d = 0; d < 4; d++)
                {
                    pair<int, int> neighborCell = {currentCell.first + dx[d],
                                                   currentCell.second + dy[d]};
                    if (isValidCell(neighborCell, n, m) &&
                        cellHeights[neighborCell.first][neighborCell.second] ==
                            -1)
                    {
                        cellHeights[neighborCell.first][neighborCell.second] =
                            heightOfNextLayer;
                        cellQueue.push({neighborCell.first, neighborCell.second});
                    }
                }
            }
            heightOfNextLayer++;
        }

        return cellHeights;
    }

private:
    bool isValidCell(pair<int, int> cell, int n, int m)
    {
        return cell.first >= 0 && cell.first < n && cell.second >= 0 &&
               cell.second < m;
    }
};

// Time Complexity : O(V + E) ~ O(n * m)
// Space Complexity : O(n * m)

// Approach 2 (Dynamic Programming)


// Initialize rows to the number of rows and columns to the number of columns of the isWater matrix.
// Initialize a 2D matrix, named cellHeights, of the same dimension as isWater. Set all of its cells to a large value, i.e. INF.
// Iterate over the cellHeights matrix and set the height of all water cells to 0.
// Loop with row from 0 to rows - 1:
// Loop with col from 0 to columns - 1:
// Initialize minNeighborDistance to INF.
// Find the neighbor above the current cell, i.e. neighborRow = row - 1, neighborCol = col.
// If the neighbor is valid, i.e. if it is not out of the bounds of the grid:
// Set minNeighborDistance to the minimum of itself and cellHeights[neighborRow][neighborCol].
// Find the neighbor to the left of the current cell, i.e. neighborRow = row, neighborCol = col - 1.
// If the neighbor is valid:
// Set minNeighborDistance to the minimum of itself and cellHeights[neighborRow][neighborCol].
// Set the height of the current cell to the minimum of its current value minNeighborDistance + 1.
// Perform the second pass over cellHeights moving in the opposite directions:
// Loop with row from rows - 1 to 0:
// Loop with col from columns - 1 to 0:
// Initialize minNeighborDistance to INF.
// Find the neighbor below the current cell, i.e. neighborRow = row + 1, neighborCol = col.
// If the neighbor is valid:
// Set minNeighborDistance to the minimum of itself and cellHeights[neighborRow][neighborCol].
// Find the neighbor to the right of the current cell, i.e. neighborRow = row, neighborCol = col + 1.
// If the neighbor is valid:
// Set minNeighborDistance to the minimum of itself and cellHeights[neighborRow][neighborCol].
// Set the height of the current cell to the minimum of its current value minNeighborDistance + 1.
// Return cellHeights.'
class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int rows = isWater.size();
        int cols = isWater[0].size();

        const int INF = rows * cols;

        vector<vector<int>> cellHeights(rows, vector<int>(cols, INF));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (isWater[i][j] == 1)
                {
                    cellHeights[i][j] = 0;
                }
            }
        }

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                int minNeighborDistance = INF;
                int neighborRow = row - 1;
                int neighborCol = col;

                if (neighborRow >= 0 && neighborRow < rows &&
                    neighborCol >= 0 && neighborCol < cols)
                {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }

                neighborRow = row;
                neighborCol = col - 1;

                if (neighborRow >= 0 && neighborRow < rows &&
                    neighborCol >= 0 && neighborCol < cols)
                {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }

                cellHeights[row][col] =
                    min(cellHeights[row][col], minNeighborDistance + 1);
            }
        }

        for (int row = rows - 1; row >= 0; row--)
        {
            for (int col = cols - 1; col >= 0; col--)
            {
                int minNeighborDistance = INF;
                int neighborRow = row + 1;
                int neighborCol = col;

                if (neighborRow >= 0 && neighborRow < rows &&
                    neighborCol >= 0 && neighborCol < cols)
                {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }

                neighborRow = row;
                neighborCol = col + 1;

                if (neighborRow >= 0 && neighborRow < rows &&
                    neighborCol >= 0 && neighborCol < cols)
                {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }

                cellHeights[row][col] =
                    min(cellHeights[row][col], minNeighborDistance + 1);
            }
        }

        return cellHeights;
    }
};

// Time Complexity : O(n * m)
// Space  Complexity : O(n * m)