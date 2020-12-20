#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> node;

// macros
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPI(i, a, b) for (int i = a; i <= b; i++)

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

int solve (node s, node f, vector<node> ims) {
    map<node, vector<pair<node, int>>> graph;
    graph[s].push_back({f, abs(s.X - f.X) + abs(s.Y - f.Y)});

    for (int i = 0; i < ims.size(); i++) {
        node im1 = ims[i];

        for (int j = i + 1; j < ims.size(); j++) {
            node im2 = ims[2];

            graph[im1].push_back({im2, min(abs(im1.X - im2.X), abs(im1.Y - im2.Y))});
            graph[im2].push_back({im1, min(abs(im1.X - im2.X), abs(im1.Y - im2.Y))});
        }

        graph[s].push_back({im1, min(abs(s.X - im1.X), abs(s.Y - im1.Y))});
        graph[im1].push_back({f, abs(f.X - im1.X) + abs(f.Y - im1.Y)});
    }

    priority_queue<pair<int, node>, vector<pair<int, node>>, greater<pair<int,node>>> pq;
    set<node> visited;

    pq.push({0, s});

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        int dist = p.first;
        node curr = p.second;

        // std::cout << dist << " (" << curr.first << "," << curr.second << ")\n";

        if (curr == f) return dist;
        if (visited.count(curr)) continue;
        visited.insert(curr);

        for (auto& edge : graph[curr]) {
            node nbor = edge.first;
            int edgeLen = edge.second;

            // std::cout << "nbor: " << edgeLen << " [" << nbor.X << "," << nbor.Y << "]\n";

            if (visited.count(nbor)) continue;

            pq.push({dist + edgeLen, nbor});
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int tests;
    // cin >> tests;

    // REP(tt, 0, tests) {
        // code here
        int n, m, sx, sy, fx, fy;

        cin >> n >> m;
        cin >> sx >> sy >> fx >> fy;

        node s = {sx, sy};
        node f = {fx, fy};

        vector<node> ims;

        // std::cout << f.X << " " << f.Y << endl;

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            ims.push_back({x, y});
        }

        std::cout << solve(s, f, ims) << "\n";
    // }

    
    std::cout.flush();
    return 0;
}