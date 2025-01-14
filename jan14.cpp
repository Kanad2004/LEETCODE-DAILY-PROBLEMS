#include <bits/stdc++.h>
using namespace std;
// Approach 1
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        vector<int> C(n);
        for (int i = 0; i < n; i++)
        {
            int commonCount = 0;
            for (int aIndex = 0; aIndex <= i; aIndex++)
            {
                for (int bIndex = 0; bIndex <= i; bIndex++)
                {
                    if (A[aIndex] == B[bIndex])
                    {
                        commonCount++;
                        break;
                    }
                }
            }
            C[i] = commonCount;
        }

        return C;
    }
};

// Time Complexity : O(N^3)
// Space Complexity : O(1)

// Approach 2
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        vector<int> C(n);
        unordered_set<int> elementsInA, elementsInB;

        for (int i = 0; i < n; i++)
        {
            elementsInA.insert(A[i]);
            elementsInB.insert(B[i]);
            int commonCount = 0;

            for (int element : elementsInA)
            {
                if (elementsInB.count(element))
                {
                    commonCount++;
                }
            }

            C[i] = commonCount;
        }

        return C;
    }
};

// Time Complexity : O(N^2)
// Space Complexity : O(N)

// Approach 3
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        vector<int> C(n, 0);
        int prefixCount = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            m[A[i]]++;
            if (m[A[i]] > 1)
            {
                count++;
            }
            m[B[i]]++;
            if (m[B[i]] > 1)
            {
                count++;
            }

            C[i] = prefixCount + count;
            prefixCount = C[i];
        }

        return C;
    }
};

// Time Complexity : O(N);
// Space Complexity : O(N) + O(N)

// Approach 4
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        vector<int> prefixCommonArray(n);
        vector<int> frequency(n + 1);
        int commonCount = 0;
        for (int currIndex = 0; currIndex < n; currIndex++)
        {
            frequency[A[currIndex]]++;
            if (frequency[A[currIndex]] > 1)
            {
                commonCount++;
            }

            frequency[B[currIndex]]++;
            if (frequency[B[currIndex]] > 1)
            {
                commonCount++;
            }

            prefixCommonArray[currIndex] = commonCount;
        }

        return prefixCommonArray;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(N)