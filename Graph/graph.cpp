#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{

public:
    map<T, vector<T>> adj;
    map<T, vector< pair<T, T>>> adj2;

    void addEdge(T u, T v, bool direction)
    {

        adj[u].push_back(v);
        if (!direction)
            (adj[v].push_back(u));
    }

    void addWeightedEdge(T u, T v, int w, bool direction)
    {

        adj2[u].push_back({v, w});
        if (!direction)
            (adj2[v].push_back({u, w}));
    }

    void printAdjList() {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            int ind = 0;
            for (auto j : i.second)
            {
                cout << j;
                if (ind < i.second.size()-1)
                    cout << ", ";
                ind++;
            }
            cout << endl;
        }
    }

    void printWeightedAdjList() {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            int ind = 0;
            for (auto j : i.second)
            {
                cout << "{" <<  j.first << ", " << j.second << "}";
                if (ind < i.second.size()-1)
                    cout << ", ";
                ind++;
            }
            cout << endl;
        }
    }

    vector<T> BFS() {

        vector<T> ans;
        vector<bool> visited(adj.size(), false);
        for (auto i : adj)
        {

            if (!visited[i.first]){
                queue<T> q;
                q.push(i.first);
                visited[i.first] = true;

                while (!q.empty())
                {
                    T front = q.front();
                    q.pop();

                    // cout << front << " ";
                    ans.push_back(front);

                    for (auto j : adj[front])
                    {
                        if (!visited[j]) {
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }

    vector<T> DFS() {

        vector<T> ans;
        vector<bool> visited(adj.size(), false);
        for (auto i : adj)
        {

            if (!visited[i.first]){
                stack<T> s;
                s.push(i.first);
                visited[i.first] = true;

                while (!s.empty())
                {
                    T top = s.top();
                    s.pop();

                    // cout << top << " ";
                    ans.push_back(top);

                    for (auto j : adj[top])
                    {
                        if (!visited[j]) {
                            s.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }

    bool hasCycleBFS() {

        vector<bool> visited(adj.size(), false);

        for (auto i : adj)
        {
            if (!visited[i.first]) {
                queue<T> q;
                q.push(i.first);
                visited[i.first] = true;

                while (!q.empty())
                {
                    T front = q.front();
                    q.pop();
                    
                    int cnt = 0;
                    for (auto j : adj[front])
                    {
                        if (!visited[j]){
                            q.push(j);
                            visited[j] = true;
                        }
                        else {
                            cnt++;
                        }

                        if (cnt >= 2){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool hasCycleDFS() {

        vector<bool> visited(adj.size(), false);

        for (auto i : adj)
        {
            if (!visited[i.first]) {
                stack<T> s;
                s.push(i.first);
                visited[i.first] = true;

                while (!s.empty())
                {
                    T top = s.top();
                    s.pop();
                    
                    int cnt = 0;
                    for (auto j : adj[top])
                    {
                        if (!visited[j]){
                            s.push(j);
                            visited[j] = true;
                        }
                        else {
                            cnt++;
                        }

                        if (cnt >= 2){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    vector<T> topoSort() {


        vector<T> ans;
        stack<T> st;
        vector<bool> visited(adj.size(), false);

        for (auto i : adj)
        {
            if (!visited[i.first]) {
                stack<T> s;
                st.push(i.first);
                s.push(i.first);
                visited[i.first] = true;

                while (!s.empty())
                {
                    T top = s.top();
                    s.pop();
                    
                    int cnt = 0;
                    for (auto j : adj[top])
                    {
                        if (!visited[j]){
                            st.push(j);
                            s.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<T> shortest_path(T u, T v)
    {

        vector<T> ans;
        vector<bool> visited(adj.size(), false);
        unordered_map<T, T> parent;

        queue<T> q;
        parent[u] = -1;
        visited[u] = true;
        q.push(u);

        while (!q.empty())
        {
            T front = q.front();
            q.pop();

            for (auto j : adj[front])
            {
                if (!visited[j])
                {
                    parent[j] = front;
                    visited[j] = true;
                    q.push(j);
                }
            }
        }

        int temp = v;
        ans.push_back(temp);
        while (temp != u)
        {
            temp = parent[temp];
            ans.push_back(temp);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> dijkstra(T u) {

        vector<int> dist(adj2.size(), INT_MAX);
        dist[u] = 0;

        priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;
        pq.push({dist[u], u});

        while (!pq.empty())
        {
            T top = pq.top().second;
            pq.pop();

            for (auto i : adj2[top])
            {
                T v = i.first;
                int w = i.second;

                if (dist[v] > dist[top] + w) {
                    dist[v] = dist[top] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    int prim(T u) {

        int minimumCost = 0;
        vector<bool> marked(adj2.size(), false);

        priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;
        pq.push({0, u});

        while (!pq.empty())
        {
            pair<int, T> top = pq.top();
            pq.pop();

            if (marked[top.second])
                continue;
            minimumCost += top.first;
            marked[top.second] = true;
            for (auto i : adj2[top.second])
            {
                if (!marked[i.first]){
                    pq.push({i.second, i.first});
                }
            }
        }
        return minimumCost;
    }

    T root(T u, unordered_map<T, T> &parent) {
        while (parent[u] != u)
        {
            parent[u] = parent[parent[u]];
            u = parent[u];
        }
        return u;
    }

    void union1(T u, T v, unordered_map<T, T> &parent) {
        parent[root(u, parent)] = parent[root(v, parent)];
    }

    int kruskal() {

        int minimumCost = 0;

        vector<bool> visited(adj2.size(), false);
        unordered_map<T, T> parent;
        vector<pair<int, pair<T, T>>> edges;

        for (auto i : adj2)
        {
            parent[i.first] = i.first;
            
            for (auto j : i.second)
            {
                if (!visited[j.first]) {
                    edges.push_back({j.second, {i.first, j.first}});
                }
            }
        }
        
        sort(edges.begin(), edges.end());

        for (int i = 0; i < edges.size(); i++)
        {
            if (root(edges[i].second.first, parent) != root(edges[i].second.second, parent)) {
                minimumCost += edges[i].first;
                union1(edges[i].second.first, edges[i].second.second, parent);
            }
        }
        return minimumCost;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    graph<int> g;

    // for (int i = 0; i < e; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     g.addEdge(u, v, 0);
    // }

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addWeightedEdge(u, v, w, 0);
    }
    
    // for (auto i : g.BFS())
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";

    // for (auto i : g.DFS())
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";

    // (g.hasCycleBFS()) ? cout << "Has Cycle\n" : cout << "No Cycle\n";
    // (g.hasCycleBFS()) ? cout << "Has Cycle\n" : cout << "No Cycle\n";

    // for (auto i : g.topoSort())
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";

    // int s, t;
    // cin >> s >> t;

    // for (auto i : g.shortest_path(s, t))
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";
    // cout << g.shortest_path(s, t).size() - 1 << "\n";

    int s;
    cin >> s;

    // for (auto i : g.dijkstra(s))
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";

    cout << g.prim(s) << "\n";
    cout << g.kruskal() << "\n";

    return 0;
}
