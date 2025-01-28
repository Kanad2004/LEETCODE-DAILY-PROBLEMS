#include <bits/stdc++.h>
using namespace std;

// Approach 1 Brute Force
class Solution
{

public:
    int countServers(vector<vector<int>> &grid)
    {
        int numRows = grid.size();
        int numCols = grid[0].size();

        int communicableServerCount = 0;

        for (int row = 0; row < numRows; row++)
        {
            for (int col = 0; col < numCols; col++)
            {
                if (grid[row][col] == 1)
                {
                    bool canCommunicate = false;
                    for (int otherCol = 0; otherCol < numCols; otherCol++)
                    {
                        if (otherCol != col && grid[row][otherCol] == 1)
                        {
                            canCommunicate = true;
                            break;
                        }
                    }

                    if (canCommunicate)
                    {
                        communicableServerCount++;
                    }
                    else
                    {
                        for (int otherRow = 0; otherRow < numRows; otherRow++)
                        {
                            if (otherRow != row && grid[otherRow][col] == 1)
                            {
                                canCommunicate = true;
                                break;
                            }
                        }
                        if (canCommunicate)
                        {
                            communicableServerCount++;
                        }
                    }
                }
            }
        }

        return communicableServerCount;
    }
};

// Time Complexity : O(n * m *( n + m))
// Space Complexity : O(1)

// Approach 2 Track Using Two Arrays

class Solution
{

public:
    int countServers(vector<vector<int>> &grid)
    {
        vector<int> rowCounts(grid.size(), 0);
        vector<int> colCounts(grid[0].size(), 0);

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    rowCounts[i]++;
                    colCounts[j]++;
                }
            }
        }

        int communicableServerCount = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    if (rowCounts[i] > 1 || colCounts[j] > 1)
                    {
                        communicableServerCount++;
                    }
                }
            }
        }

        return communicableServerCount;
    }
};

// Space Complexity : O(n * m)
// Space Complexity : O(n + m)



