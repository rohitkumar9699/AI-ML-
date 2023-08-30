#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void dfsTopological(int v, vector<int> adj[], vector<bool>& visited, stack<int>& result) {
    visited[v] = true;

    for (int u : adj[v]) {
        if (!visited[u]) {
            dfsTopological(u, adj, visited, result);
        }
    }

    result.push(v);
}

int main() {
    vector<int> adj[5];
    bool visited[5];

    for (int i = 0; i < 5; i++) {
        visited[i] = false;
    }

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);

    stack<int> result;
    for (int i = 0; i < 5; i++) {
        if (!visited[i]) {
            dfsTopological(i, adj, visited, result);
        }
    }
    cout << "Topological Sorting: ";
    while (!result.empty()) 
    {
        cout << result.top() << " ";
        result.pop();
    }

    return 0;
}
