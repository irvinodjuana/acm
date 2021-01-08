#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// macros
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPI(i, a, b) for (int i = a; i <= b; i++)

void print_vector(vector<ull> v) {
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

// nodes: [weight, idx]
// edges: [idx1, idx2]
vector<ull> k_colorings(int n, vector<pair<int,int>>& nodes, vector<pair<int,int>>& edges) {
    sort(nodes.begin(), nodes.end(), greater<pair<int,int>>());
    
    ull wsum = 0;
    for (auto [weight, idx] : nodes) wsum += weight;

    unordered_map<int,int> freeEdges;

    for (auto [i, j] : edges) {
        freeEdges[i]++;
        freeEdges[j]++;
    }

    for (auto& p : freeEdges) {
        p.second--;
        // printf("%d, %d\n", p.first, p.second);
    }

    int start = 0;
    vector<ull> kvals {wsum};

    for (int k = 2; k <= n-1; k++) {
        auto [weight, idx] = nodes[start];

        while (start < n && freeEdges[idx] <= 0) {
            start++;
            auto [w, i] = nodes[start];
            weight = w;
            idx = i;
        }

        freeEdges[idx]--;
        // printf("[%d, %d]\n", idx, weight);

        wsum += weight;
        kvals.push_back(wsum);
    }

    return kvals;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        vector<int> weights;
        int n;
        cin >> n;
        read_array(weights, n);
        vector<pair<int,int>> nodes; // [weight, idx]

        for (int i = 0; i < n; i++) {
            nodes.push_back({weights[i], i+1});
        }

        vector<pair<int,int>> edges;

        for (int i = 0; i < n-1; i++) {
            int idx1, idx2;
            cin >> idx1 >> idx2;
            edges.push_back({idx1,idx2});
        }

        auto res = k_colorings(n, nodes, edges);
        print_vector(res);
    }

    
    cout.flush();
    return 0;
}