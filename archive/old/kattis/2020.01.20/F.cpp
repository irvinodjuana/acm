#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;

void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void read_array(vector<int> & v, int n) {
    int num;
    while (n--) {
        cin >> num;
        v.push_back(num);
    }
}

ull soln(int n, int m, int f, int s, int t, vector<vector<int>>& edges) {
    unordered_map<int, vector<vector<int>>> graph;

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int c = edge[2];
        graph[u].push_back({v, c});
    }


    priority_queue<pair<ull, int>, vector<pair<ull,int>>, greater<pair<ull,int>>> pq; // [dist, node]
    pq.push({0, s});

    vector<bool> seen(n, false);
    bool flightUsed = false;

    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();

        if (seen[node]) continue;
        seen[node] = true;
        if (node == t) return dist;

        for (auto& edge : graph[node]) {
            int nbor = edge[0];
            int cost = edge[1];

            if (!seen[nbor]) {
                pq.push({dist + cost, nbor});
            }
        }
    }

    return ULLONG_MAX;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Code
    int n, m, f, s, t;
    cin >> n >> m >> f >> s >> t;
    vector<vector<int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
        edges.push_back({v, u, c});
    }

    for (int i = 0; i < f; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v, -1});
    }

    cout << soln(n, m, f, s, t, edges) << "\n";
    
    cout.flush();
    return 0;
}