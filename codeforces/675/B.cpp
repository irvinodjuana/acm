#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

// macros
#define F first
#define S second
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

ll solve(vector<vector<int>>& grid, int n, int m) {
    ll diff = 0;

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            vector<ll> square {grid[i][j], grid[i][m-j-1], grid[n-i-1][j], grid[n-i-1][m-j-1]};
            sort(square.begin(), square.end());
            diff += (square[1] - square[0]) + (square[2] - square[1]) + (square[3] - square[1]);
        }
    }

    if (n % 2 == 1) {
        for (int j = 0; j < m / 2; j++) {
            diff += abs(grid[n/2][j] - grid[n/2][m-j-1]);
        }
    }

    if (m % 2 == 1) {
        for (int i = 0; i < n / 2; i++) {
            diff += abs(grid[i][m/2] - grid[n-i-1][m/2]);
        }
    }

    return diff;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n);

        for (int i = 0; i < n; i++) {
            read_array(grid[i], m);
        }

        cout << solve(grid, n, m) << "\n";
    }

    
    cout.flush();
    return 0;
}