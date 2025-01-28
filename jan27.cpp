#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool dfs(int node, int dst, vector<vector<int>> &adj, int n, vector<int> &visited)
    {
        if (node == dst)
        {
            return true;
        }
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it] && dfs(it, dst, adj, n, visited))
            {
                return true;
            }
        }

        return false;
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<bool> result;
        for (int i = 0; i < queries.size(); i++)
        {
            int src = queries[i][0];
            int dst = queries[i][1];
            vector<int> visited(numCourses, 0);
            if (dfs(src, dst, adj, numCourses, visited))
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }

        return result;
    }
};