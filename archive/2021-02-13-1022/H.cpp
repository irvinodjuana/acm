#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// common utils

vector<vector<int>> read_matrix(int n, int m) {
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = (s[j] - '0');
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

vector<int> read_vector(int n) {
    vector<int> v;

    int num;
    while (n--) {
        cin >> num;
        v.push_back(num);
    }

    return v;
}


// solution code
unordered_map<int, int> dp;
vector<vector<int>> grid;
string code;

int memo(int i, int j, int k) {
    int key = i * 1e6 + j * 1e3 + k;
    if (dp.count(key)) return dp[key];
    int m = grid[0].size();
    if (i == 0 && j == m-1) return 0;

    // printf("%d %d\n", i, j);

    int res = INT_MAX;
    

    if (i > 0)              res = min(res, memo(i-1, j, k) + grid[i-1][j]); // step up
    if (j < m-1)            res = min(res, memo(i, j+1, k) + grid[i][j+1]); // step right

    if (k < code.size()) {
        int hop = (code[k] - '0') + 1;
        if (i >= hop)       res = min(res, memo(i-hop, j, k+1) + grid[i-hop][j]);
        if (j+hop <= m-1)    res = min(res, memo(i, j+hop, k+1) + grid[i][j+hop]); 
    }
    
    dp[key] = res;
    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int n, m;
    cin >> m >> n;
    cin >> code;
    // printf("%d\n", code.size());
    grid = read_matrix(n, m);

    // printf("%d %d\n", grid.size(), grid[0].size());

    int ans = grid[n-1][0] + memo(n-1, 0, 0);
    printf("%d\n", ans);
    
    
    cout.flush();
    return 0;
}