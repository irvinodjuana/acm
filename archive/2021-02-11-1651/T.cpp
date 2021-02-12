#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

vector<vector<char>> read_mtx(int n, int m) {
    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j];
        }
    }

    return grid;
}

bool inBounds(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

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

void DFS_land(int i, int j, int n, int m, vector<vector<char>>& grid) {
    if (!inBounds(i, j, n, m)) return;
    if (grid[i][j] != 'C') return;
    grid[i][j] = 'L';

    DFS_land(i-1, j, n, m, grid);
    DFS_land(i+1, j, n, m, grid);
    DFS_land(i, j-1, n, m, grid);
    DFS_land(i, j+1, n, m, grid);
}

void DFS_find(int i, int j, int n, int m, vector<vector<char>>& grid) {
    if (!inBounds(i, j, n, m)) return;
    if (grid[i][j] != 'L') return;
    grid[i][j] = 'W';

    DFS_find(i-1, j, n, m, grid);
    DFS_find(i+1, j, n, m, grid);
    DFS_find(i, j-1, n, m, grid);
    DFS_find(i, j+1, n, m, grid);
}

int soln(int n, int m, vector<vector<char>>& grid) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'L') {
                DFS_land(i-1, j, n, m, grid);
                DFS_land(i+1, j, n, m, grid);
                DFS_land(i, j-1, n, m, grid);
                DFS_land(i, j+1, n, m, grid);
            }
        }
    }

    int islandCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'L') {
                islandCount++;
                DFS_find(i, j, n, m, grid);
            }
        }
    }

    return islandCount;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int n, m;
    cin >> n >> m;

    auto grid = read_mtx(n, m);

    cout << soln(n, m, grid) << "\n";
    
    cout.flush();
    return 0;
}