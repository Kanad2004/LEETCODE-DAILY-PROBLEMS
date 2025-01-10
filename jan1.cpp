#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {
        int n = s.length();
        int totalOnes = 0;

        // Step 1: Count total ones in the string
        for (char c : s)
        {
            if (c == '1')
            {
                totalOnes++;
            }
        }

        int leftZeros = 0;         // Count of zeros in the left substring
        int rightOnes = totalOnes; // Count of ones in the right substring
        int maxScore = 0;

        // Step 2: Iterate through the string to find the maximum score
        for (int i = 0; i < n - 1; ++i)
        { // Last split must leave non-empty right substring
            if (s[i] == '0')
            {
                leftZeros++;
            }
            else
            {
                rightOnes--;
            }

            // Calculate score for the current split
            maxScore = max(maxScore, leftZeros + rightOnes);
        }

        return maxScore;
    }
};
