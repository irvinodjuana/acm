#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// common utils

vector<vector<char>> read_matrix(int n, int m) {vector<vector<char>> grid(n, vector<char>(m));for (int i = 0; i < n; i++) {string s;cin >> s;for (int j = 0; j < m; j++) {grid[i][j] = s[j];}}return grid;}
bool in_bounds(int i, int j, int n, int m) {return i >= 0 && i < n && j >= 0 && j < m;}
void print_vector(vector<int> v) {for (int i = 0; i < v.size(); i++) {cout << v[i] << " ";}cout << "\n";}
vector<int> read_vector(int n) {vector<int> v;int num;while (n--) {cin >> num;v.push_back(num);}return v;}

int MOD = 998244353;

// solution code
int pow(int x, int n, int mod) {
    if (n == 0) return 1;
    if (n == 1) return x % mod;

    if (x % 2 == 0) {
        int res = pow(x, n/2, mod);
        return (res * res) % mod;
    } else {
        int res = pow(x, n-1, mod);
        return (x * res) % mod;
    }
}

// num rainbows w/ size n and fixed first digit
int rd(int n) {
    if (n <= 0) return 0;
    return pow(9, n-1, MOD);
}

bool is_rainbow(string& s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) return false;
    }
    return true;
}

// num rainbows less than s
int rainbow(string s) {
    int n = s.size();
    int n_i = n;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int dig = s[i] - '0';

        if (i >= 1 && (s[i-1] == s[i])) {
            dig--;
        }

        sum += dig * rd(n_i);
        n_i--;
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    string L;
    string U;
    cin >> L;
    cin >> U;

    int ans = (rainbow(U) - rainbow(L)) % MOD;
    if (is_rainbow(L)) ans++;

    printf("%d\n", ans);
    
    cout.flush();
    return 0;
}