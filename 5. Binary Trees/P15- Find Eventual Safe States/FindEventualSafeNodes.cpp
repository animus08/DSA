#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfsCheck(int node, int vis[], int pathVis[], int check[], vector<int> adj[])
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfsCheck(it, vis, pathVis, check, adj))
                {
                    return true;
                }
            }
            else if (pathVis[it])
            {
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        vector<int> safeNodes;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsCheck(i, vis, pathVis, check, adj);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
            {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
}; 

int main()
{
    int V = 7;
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {2, 3};
    adj[2] = {5};
    adj[3] = {0};
    adj[4] = {5};
    adj[5] = {};
    adj[6] = {4};

    Solution obj;
    vector<int> safeNodes = obj.eventualSafeNodes(V, adj);

    cout << "Eventual Safe Nodes: ";
    for (int node : safeNodes)
    {
        cout << node << " ";
    }
    cout << endl;
}
