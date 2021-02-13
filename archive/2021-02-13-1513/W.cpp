#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<string, string> pss;

// common utils

vector<vector<char>> read_matrix(int n, int m) {vector<vector<char>> grid(n, vector<char>(m));for (int i = 0; i < n; i++) {string s;cin >> s;for (int j = 0; j < m; j++) {grid[i][j] = s[j];}}return grid;}
bool inBounds(int i, int j, int n, int m) {return i >= 0 && i < n && j >= 0 && j < m;}
void print_vector(vector<int> v) {for (int i = 0; i < v.size(); i++) {cout << v[i] << " ";}cout << "\n";}
vector<int> read_vector(int n) {vector<int> v;int num;while (n--) {cin >> num;v.push_back(num);}return v;}



double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = (x2 - x1);
    double dy = (y2 - y1);
    double dz = (z2 - z1);

    return sqrt(dx*dx + dy*dy + dz*dz);
}

// fill all shortest distances from s
void dijkstra(unordered_map<int, unordered_map<int, double>>& graph, vector<vector<double>>& distances, int s, int n) {
    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
    pq.push({0, s});

    vector<bool> seen(n);

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int v = p.second;
        double dv = p.first;

        if (seen[v]) continue;
        seen[v] = true;
        distances[s][v] = dv;

        for (auto nbr : graph[v]) {
            if (!seen[nbr.first]) {
                pq.push({dv + nbr.second, nbr.first});
            }
        }
    }
}

// solution code
string soln(vector<string> planets,
        vector<double> x,
        vector<double> y,
        vector<double> z,
        vector<pss> wormholes,
        vector<pss> queries,
        int p, int w, int q) 
{
    unordered_map<int, unordered_map<int, double>> graph;
    unordered_map<string, int> idx;

    for (int i = 0; i < p; i++) {
        idx[planets[i]] = i;

        for (int j = i+1; j < p; j++) {
            double dij = dist(x[i], y[i], z[i],
                              x[j], y[j], z[j]);
            graph[i][j] = dij;
            graph[j][i] = dij;

            // printf("%s %s - %f\n", planets[i].c_str(), planets[j].c_str(), dij);
        }
    }

    for (auto pr : wormholes) {
        int u = idx[pr.first];
        int v = idx[pr.second];
        graph[u][v] = 0;
    }

    string ans = "";
    vector<vector<double>> distances(p, vector<double>(p, -1));

    // printf("queries: %d\n", (int) queries.size());

    for (auto pr : queries) {
        int s = idx[pr.first];
        int t = idx[pr.second];

        if (distances[s][t] == -1) {
            dijkstra(graph, distances, s, p);
        }

        // printf("res : %s %s - %f %f\n", planets[s].c_str(), planets[t].c_str(), distances[s][t], graph[s][t]);

        int dst = round(distances[s][t]);
        string resp = "The distance from " + pr.first + " to " + pr.second + " is " + to_string(dst) + " parsecs.\n";
        // cout << resp << endl;
        ans += resp;
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int T;
    cin >> T;

    string output = "";

    for (int t = 0; t < T; t++) {
        vector<string> planets;
        vector<double> x;
        vector<double> y;
        vector<double> z;
        vector<pss> wormholes;
        vector<pss> queries;

        int p;
        cin >> p;

        for (int i = 0; i < p; i++) {
            string name;
            double x1, y1, z1;
            cin >> name >> x1 >> y1 >> z1;
            planets.push_back(name);
            x.push_back(x1);
            y.push_back(y1);
            z.push_back(z1);
        }

        int w;
        cin >> w;

        for (int i = 0; i < w; i++) {
            string a, b;
            cin >> a >> b;
            wormholes.push_back({a,b});
        }

        int q;
        cin >> q;

        for (int i = 0; i < q; i++) {
            string a, b;
            cin >> a >> b;
            queries.push_back({a,b});
        }

        string ans = soln(planets, x, y, z, wormholes, queries, p, w, q);
        output += "Case " + to_string(t+1) + ":\n";
        output += ans;
    }

    cout << output;
    
    cout.flush();
    return 0;
}