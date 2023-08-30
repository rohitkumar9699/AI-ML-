#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
using namespace std;
bool bfs(int node, unordered_map<int, bool>& visited,unordered_map<int, list<int>>& adj)
{
    unordered_map<int, int> parents;
    parents[node] = -1;
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto i : adj[u])
        {
            if (visited[i] && i != parents[u])
            {
                return true;
            }
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                parents[i] = u;
            }
        }
    }
    return false; // No cycle detected
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    bool cycleDetected = false;
    for (int i = 0; i < node; i++)
    {
        if (!visited[i])
        {
            if (bfs(i, visited, adj))
            {
                cout<<"YES";
                return 0; // Cycle detected
            }
        }
    }
    cout<< "No"; // No cycles detected
    return 0;
}