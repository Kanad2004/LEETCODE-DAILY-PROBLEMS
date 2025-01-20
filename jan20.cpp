#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> rowCount(n, 0);
        vector<int> colCount(m, 0);

        vector<int> numToRow(n * m, 0);
        vector<int> numToCol(n * m, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                numToRow[mat[i][j] - 1] = i;
                numToCol[mat[i][j] - 1] = j;
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            int row = numToRow[arr[i] - 1];
            int col = numToCol[arr[i] - 1];

            rowCount[row]++;

            if (rowCount[row] == m)
            {
                return i;
            }

            colCount[col]++;
            if (colCount[col] == n)
            {
                return i;
            }
        }

        return -1;
    }
};

// Time Complexity : O(n * m)
// Space Complexity : O(n * m)