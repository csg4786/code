#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{

public:
    vector<vector<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        adj[u].push_back(v);
        if (!direction)
            (adj[v].push_back(u));
    }

    

};

int main()
{
    int n, e;
    cin >> n >> e;

    graph<int> g;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    return 0;
}
