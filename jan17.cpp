#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        vector<int> original = {0};
        for (int i = 0; i < derived.size(); i++)
        {
            original.push_back((derived[i] ^ original[i]));
        }

        bool checkForZero = (original[0] == original[original.size() - 1]);

        if (checkForZero)
        {
            return true;
        }

        original = {1};

        for (int i = 0; i < derived.size(); i++)
        {
            original.push_back((derived[i] ^ original[i]));
        }

        bool checkForOne = (original[0] == original[original.size() - 1]);

        return checkForOne;
    }
};

// Time Complexity : O(N) + O(N)
// Space Complexity : O(N)

// Approach 2
class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int XOR = 0;
        for (int i = 0; i < derived.size(); i++)
        {
            XOR = XOR ^ derived[i];
        }

        return !XOR;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

// Approach 3
class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int sum = accumulate(derived.begin(), derived.end(), 0);
        return sum % 2 == 0;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
