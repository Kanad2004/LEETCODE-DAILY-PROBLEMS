#include <bits/stdc++.h>
using namespace std;

//! Approach 1 Sorting
//! Time Complexity O(NlogN)
//! Space Complexity O(N)

class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        int n = weights.size();
        if (k == 1 || k == n)
        {
            return 0;
        }

        vector<long long> pairSums;
        for (int i = 0; i < n - 1; i++)
        {
            pairSums.push_back((long long)weights[i] + weights[i + 1]);
        }

        sort(pairSums.begin(), pairSums.end());

        long long minScore = 0, maxScore = 0;

        for (int i = 0; i < k - 1; i++)
        {
            minScore += pairSums[i];
            maxScore += pairSums[pairSums.size() - 1 - i];
        }

        return maxScore - minScore;
    }
};

//! Approach 2 Heap
//! Time Complexity O(NlogK)
//! Space Complexity O(K)
class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        int n = weights.size();
        if (k == 1 || n == k)
            return 0;

        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

        priority_queue<long long> maxHeap;

        for (int i = 0; i < n - 1; i++)
        {
            long long pairSum = (long long)weights[i] + weights[i + 1];
            minHeap.push(pairSum);
            maxHeap.push(pairSum);

            if (minHeap.size() > k - 1)
                minHeap.pop();
            if (maxHeap.size() > k - 1)
                maxHeap.pop();
        }

        long long minScore = 0, maxScore = 0;

        while (!minHeap.empty())
        {
            maxScore += minHeap.top();
            minHeap.pop();
        }

        while (!maxHeap.empty())
        {
            minScore += maxHeap.top();
            maxHeap.pop();
        }

        return maxScore - minScore;
    }
};

//! Approach 3 Two Pointer Approach (Greedy)
//! Time Complexity O(N)
//! Space Complexity O(N)

class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        int n = weights.size();
        if (k == 1 || n == k)
            return 0;

        vector<long long> pairSums(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            pairSums[i] = (long long)weights[i] + weights[i + 1];
        }

        nth_element(pairSums.begin(), pairSums.begin() + (k - 1), pairSums.end());

        long long minScore = 0;

        for (int i = 0; i < k - 1; i++)
        {
            minScore += pairSums[i];
        }

        nth_element(pairSums.begin(), pairSums.begin() + (n - k), pairSums.end());

        long long maxScore = 0;

        for (int i = n - 2; i >= n - k; i--)
        {
            maxScore += pairSums[i];
        }

        return maxScore - minScore;
    }
};