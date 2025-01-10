#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> answer(n, 0);

        // For each box, calculate the total operations needed
        for (int i = 0; i < n; ++i)
        {
            int operations = 0;
            for (int j = 0; j < n; ++j)
            {
                if (boxes[j] == '1')
                {                             // If there's a ball in box j
                    operations += abs(i - j); // Add the distance between i and j
                }
            }
            answer[i] = operations; // Store the result for box i
        }

        return answer;
    }
};

// Time  Complexity : O(n^2)
// Space Complexity : O(n)

// Approach 2
class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> answer(n, 0);

        // Pass 1: Left-to-right
        int count = 0;      // Count of balls seen so far
        int operations = 0; // Total operations to bring all seen balls to the current box
        for (int i = 0; i < n; ++i)
        {
            answer[i] += operations; // Add the total operations so far
            if (boxes[i] == '1')
                ++count;         // Increment ball count if the box has a ball
            operations += count; // Add the cost of moving all seen balls one step right
        }

        // Pass 2: Right-to-left
        count = 0;      // Reset count of balls
        operations = 0; // Reset total operations
        for (int i = n - 1; i >= 0; --i)
        {
            answer[i] += operations; // Add the total operations so far
            if (boxes[i] == '1')
                ++count;         // Increment ball count if the box has a ball
            operations += count; // Add the cost of moving all seen balls one step left
        }

        return answer;
    }
};

// Time Complexity : 2 * O(n)
// Space Complexity : O(n)