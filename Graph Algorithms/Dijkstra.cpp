#include <bits\stdc++.h>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
vector<PII> adj[MAX];
int dist[MAX];
bool vis[MAX];

void dijkstra()
{
    for (int i = 0; i < MAX; i++)
    {
        dist[i] = INT_MAX;
    }
    
    for (int i = 0; i < MAX; i++)
    {
        vis[i] = false;
    }
    
    dist[1] = 0;
    multiset<pair<int, int>> s; 

    s.insert({0, 1}); 

    while (!s.empty())
    {

        pair<int, int> p = *s.begin(); 
        s.erase(s.begin());

        int x = p.second;
        int wei = p.first;
        if (vis[x])
            continue; 
        vis[x] = true;

        for (int i = 0; i < adj[x].size(); i++)
        {
            int e = adj[x][i].second;
            int w = adj[x][i].first;
            if (dist[x] + w < dist[e])
            { 
                dist[e] = dist[x] + w;
                s.insert({dist[e], e}); 
            }
        }
    }
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }

    dijkstra();

    for (int i = 1; i < nodes+1; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
