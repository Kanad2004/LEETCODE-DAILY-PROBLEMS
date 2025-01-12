#include <bits/stdc++.h>
using namespace std;

//Approach 1
class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        int n = s.length();
        if (n % 2 != 0)
            return false; // Odd length can't form a valid parentheses string

        // Forward pass
        int open = 0, flexible = 0;
        for (int i = 0; i < n; i++)
        {
            if (locked[i] == '0')
            {
                flexible++;
            }
            else if (s[i] == '(')
            {
                open++;
            }
            else
            { // s[i] == ')'
                if (open > 0)
                {
                    open--;
                }
                else if (flexible > 0)
                {
                    flexible--;
                }
                else
                {
                    return false; // Too many unmatched ')'
                }
            }
        }

        // Reset for backward pass
        open = 0, flexible = 0;

        // Backward pass
        for (int i = n - 1; i >= 0; i--)
        {
            if (locked[i] == '0')
            {
                flexible++;
            }
            else if (s[i] == ')')
            {
                open++;
            }
            else
            { // s[i] == '('
                if (open > 0)
                {
                    open--;
                }
                else if (flexible > 0)
                {
                    flexible--;
                }
                else
                {
                    return false; // Too many unmatched '('
                }
            }
        }

        return true;
    }
};

//Time Complexity : O(n)
//Space Complexity : O(1)