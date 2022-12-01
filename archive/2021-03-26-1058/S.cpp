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


// solution code

int count_bits(int n) {
    int bits = 0;

    while (n) {
        bits += n & 1;
        n >>= 1;
    }

    return bits;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int n, k;
    cin >> n >> k;
    vector<int> nums;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = 0;
        for (char c : s) {
            x <<= 1;
            if (c == 'T') {
                x |= 1;
            }
        }
        nums.push_back(x);
    }

    int minval = k;

    for (int test = 0; test < (2 << k); test++) {
        int maxerr = 0;

        for (int x : nums) {
            maxerr = max(maxerr, count_bits(test ^ x));
        }

        minval = min(minval, maxerr);
    }

    printf("%d\n", k - minval);
    
    cout.flush();
    return 0;
}