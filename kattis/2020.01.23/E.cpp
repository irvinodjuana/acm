#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ll;

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

bool inBounds(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

ll soln(vector<vector<int>>& grid, int n, int m, int x, int y) {
    vector<vector<int>> flows(n, vector<int>(m, 0));
    vector<vector<bool>> seen(n, vector<bool>(m, false));
    vector<int> dis = {-1, 0, 1};
    vector<int> djs = {-1, 0, 1};

    priority_queue<vector<int>> pq;
    pq.push({INT_MAX, x, y});

    while (!pq.empty()) {
        auto vec = pq.top();
        int f = vec[0], i = vec[1], j = vec[2];
        pq.pop();

        if (seen[i][j]) continue;
        seen[i][j] = true;
        flows[i][j] = min(abs(grid[i][j]), f);

        for (int di : dis) {
            for (int dj : djs) {
                int i1 = i+di, j1 = j+dj;

                if (inBounds(i1, j1, n, m) && grid[i1][j1] < 0 && !seen[i1][j1]) {
                    // printf("%d %d | %d | %d %d\n", i, j, flows[i][j], i1, j1);
                    pq.push({flows[i][j], i1, j1});
                }
            }
        }
    }

    ll res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // printf("%3d ", flows[i][j]);
            res += flows[i][j];
        }
        // printf("\n");
    }

    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Code
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid;

    for (int i = 0; i < n; i++) {
        vector<int> row;
        read_array(row, m);
        grid.push_back(row);
    }

    int i, j;
    cin >> i >> j;

    cout << soln(grid, n, m, i-1, j-1) << endl;
    
    
    cout.flush();
    return 0;
}