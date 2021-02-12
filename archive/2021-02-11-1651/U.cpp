#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// common utils

vector<vector<char>> read_matrix(int n, int m) {vector<vector<char>> grid(n, vector<char>(m));for (int i = 0; i < n; i++) {string s;cin >> s;for (int j = 0; j < m; j++) {grid[i][j] = s[j];}}return grid;}
bool inBounds(int i, int j, int n, int m) {return i >= 0 && i < n && j >= 0 && j < m;}
void print_vector(vector<int> v) {for (int i = 0; i < v.size(); i++) {cout << v[i] << " ";}cout << "\n";}
vector<int> read_vector(int n) {vector<int> v;int num;while (n--) {cin >> num;v.push_back(num);}return v;}


// solution code

ull soln(int n, int k, vector<pair<int,int>>& xm) {
    sort(xm.begin(), xm.end());
    vector<int> x;
    vector<int> m;

    for (auto p : xm) {
        x.push_back(p.first);
        m.push_back(p.second);
    }

    // printf("sizes %lu %lu\n", x.size(), m.size());

    int neg = n-1;

    for (int i = 0; i < n; i++) {
        if (x[i] > 0) {
            neg = i - 1;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        // printf("xm %d - %d %d\n", i, x[i], m[i]);
    }

    ull time = 0;

    // negatives
    for (int i = 0; i <= neg; i++) {
        if (m[i] <= 0) continue;

        ull trips = m[i] / k;
        ull extra = m[i] % k;

        time += trips * abs(2 * x[i]);
        

        if (extra) {
            time += abs(2 * x[i]);
            if (i < neg) {
                m[i+1] -= (k - extra);
            }
        }

        // printf("neg - %d: %d %d - %llu\n", i, x[i], m[i], time);
    }

    // positives
    for (int i = n-1; i >= neg+1; i--) {
        if (m[i] <= 0) continue;

        ull trips = m[i] / k;
        ull extra = m[i] % k;

        time += trips * abs(2 * x[i]);

        

        if (extra) {
            time += abs(2 * x[i]);
            if (i > neg+1) {
                m[i-1] -= (k - extra);
            }
        }

        // printf("pos - %d: %d %d - %llu\n", i, x[i], m[i], time);
    }

    return time;
} 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> xm;

    for (int i = 0; i < n; i++) {
        int x, m;
        cin >> x >> m;
        xm.push_back({x, m});
    }
    
    cout << soln(n, k, xm) << "\n";

    cout.flush();
    return 0;
}