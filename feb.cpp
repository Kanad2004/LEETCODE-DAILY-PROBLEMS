#include <bits/stdc++.h>
using namespace std;

//! Best Approach
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int count = 0;
        vector<char> first;
        vector<char> second;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                count++;
                if (count == 1)
                {
                    first.push_back(s1[i]);
                    second.push_back(s2[i]);
                }
                else if (count == 2)
                {
                    first.push_back(s1[i]);
                    second.push_back(s2[i]);
                }
            }
        }

        if (count == 0)
        {
            return true;
        }

        if (count == 2)
        {
            if (first[0] == second[1] && first[1] == second[0])
                return true;
        }

        return false;
    }
};

//! Time Complexity : O(N)
//! Space Complexity : O(1)