#include <bits/stdc++.h>
using namespace std;

// Approach 1 (DFS - Brute Force)
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
            adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());

            if (isConnectedAndAcyclic(adj, n))
            {
                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }

private:
    bool isConnectedAndAcyclic(vector<vector<int>> &adj, int n)
    {
        unordered_set<int> visited;
        dfs(1, adj, visited);

        if (visited.size() != n)
        {
            return false;
        }

        return !hasCycle(adj, n);
    }

    void dfs(int node, vector<vector<int>> &adj, unordered_set<int> &visited)
    {
        visited.insert(node);
        for (int neighbor : adj[node])
        {
            if (visited.find(neighbor) == visited.end())
            {
                dfs(neighbor, adj, visited);
            }
        }
    }

    bool hasCycle(vector<vector<int>> &adj, int n)
    {
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && hasCycleUtil(adj, visited, i, -1))
            {
                return true;
            }
        }
        return false;
    }

    bool hasCycleUtil(vector<vector<int>> &adj, vector<bool> &visited, int node, int parent)
    {
        visited[node] = true;
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                if (hasCycleUtil(adj, visited, neighbor, node))
                {
                    return true;
                }
            }
            else if (neighbor != parent)
            {
                return true;
            }
        }

        return false;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n)


class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            int rootU = find(parent, u);
            int rootV = find(parent, v);

            if (rootU == rootV)
            {
                return edge;
            }

            parent[rootV] = rootU;
        }

        return {};
    }

private:
    int find(vector<int> &parent, int node)
    {
        while (parent[node] != node)
        {
            node = parent[node];
        }

        return node;
    }
};