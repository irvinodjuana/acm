#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ll;
typedef vector<int> vi;

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
    // printf("%d %d %d %d\n", i, j, n, m);
    return i >= 0 && i < n && j >= 0 && j < m;
}

string soln(int n, int m, vector<vector<int>>& grid) {
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};

    priority_queue<vi, vector<vi>, greater<vi>> pq; 
    pq.push({0,0,0}); // [moves, i, j]
    vector<vector<bool>> seen(n, vector<bool>(m, false));

    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();
        int moves = v[0], i = v[1], j = v[2];

        if (i == n-1 && j == m-1) return to_string(moves);
        if (seen[i][j]) continue;
        seen[i][j] = true;

        // printf("(%d, %d): %d\n", i, j, moves);

        for (auto d : dirs) {
            int k = grid[i][j];
            

            for (auto d : dirs) {
                int i2 = i + d[0] * k;
                int j2 = j + d[1] * k;

                if (i == 3) {
                    // printf("%d, %d, %d\n", k, i2, j2);
                }
                

                if (inBounds(i2, j2, n, m) && !seen[i2][j2]) {
                    pq.push({moves + 1, i2, j2});
                    // printf("[%d, %d] push: (%d, %d): %d\n", i, j, i2, j2, moves + 1);
                }
            }
        }
    }

    return "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Code
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            grid[i][j] = (s[j] - '0');   
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         printf("%d ", grid[i][j]);
    //     }
    //     printf("\n");
    // }

    cout << soln(n, m, grid) << "\n";
    
    
    cout.flush();
    return 0;
}