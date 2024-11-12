#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, wt;
};

bool bellman(vector<Edge> &edges, int V, int E, int src)
{
    vector<int> d(V, INT_MAX);
    d[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (auto &e : edges)
        {
            if (d[e.u] != INT_MAX && d[e.u] + e.wt < d[e.v])
            {
                d[e.v] = d[e.u] + e.wt;
            }
        }
    }

    // negative cycle checking -
    for (auto &e : edges)
    {
        if (d[e.u] != INT_MAX && d[e.u] + e.wt < d[e.v])
        {
            return false;
        }
    }
    cout << "Distance of all vertices from soruce node- " << endl;
    for (int i = 0; i < V; i++)
    {
        if (i == src)
            cout << "Node " << i << ": Source " << endl;
        else if (d[i] == INT_MAX)
            cout << "Node " << i << ": INT(Not reachable) " << endl;
        else
            cout << "Node " << i << ": " << d[i] << endl;
    }
    return true;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    int src;
    cin >> src;
    if (bellman(edges, V, E, src))
    {
        cout << "No Negative Cycle detected" << endl;
    }
    else
        cout << "Negative Cycle detected!" << endl;
    return 0;
}
