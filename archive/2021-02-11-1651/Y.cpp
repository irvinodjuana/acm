#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// common utils

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
int soln(int n, vector<int>& a) {
    vector<int> inc(n, 1);
    vector<int> dec(n, 1);
    int best = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                inc[i] = max(inc[i], dec[j] + 1);
            } else if (a[j] > a[i]) {
                dec[i] = max(dec[i], inc[j] + 1);
            }
        }
        best = max(best, max(inc[i], dec[i]));
    }

    return best;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int n;
    cin >> n;
    auto a = read_vector(n);

    cout << soln(n, a) << "\n";

    cout.flush();
    return 0;
}