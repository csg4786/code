// Dijkstra's algorithm is used to find shortest path in undirected graph
//  Time Complexity:= O((N+E)log N) === NlogN
//  Space Complexity:= O(N) + O(N)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];

    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        g[a].push_back({b, wt});
        g[b].push_back({a, wt});
    }

    int src;
    cin >> src;

    // Dijkstra's algorithm begins from here

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap: In pair => (dist)

    vector<int> distTo(n + 1, INT_MAX);

    distTo[src] = 0;
    pq.push({0, src}); // {dist,from}

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int, int>>::iterator it;

        for (it = g[prev].begin(); it != g[prev].end(); it++)
        {

            int next = it->first;      // equivalent to it.first
            int nextDist = it->second; // equivalent to it.second

            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push({distTo[next], next});
            }
        }
    }

    cout << "The distances form source, " << src << ", are: \n";
    for (int i = 1; i <= n; i++)
        cout << distTo[i] << " ";

    return 0;
}