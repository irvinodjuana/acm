#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// common utils
vector<vector<char>> read_matrix(int n, int m);
bool in_bounds(int i, int j, int n, int m);
void print_vector(vector<int> v);
vector<int> read_vector(int n);

int choose(int n, int k);
int factorial(int n);
int gcd(int a, int b);


// solution code
int soln(int X, int Y, string& s) {
    int ans = 0;
    int prev = s[0];

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '?') continue;
        if (prev == 'C' && s[i] == 'J') ans += X;
        if (prev == 'J' && s[i] == 'C') ans += Y;
        prev = s[i];
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int T;
    cin >> T;
    vector<int> output;

    for (int t = 0; t < T; t++) {
        int X, Y;
        string s;
        cin >> X >> Y >> s;
        output.push_back(soln(X, Y, s));
    }

    for (int i = 0; i < T; i++) {
        printf("Case #%d: %d\n", i+1, output[i]);
    }
    
    cout.flush();
    return 0;
}




/**
 * Implementation of common utils code here
 */

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

// n choose k
int choose(int n, int k) {
    int res = 1;

    if (n - k < k) k = n - k;

    for (int i = 1; i <= k; i++) {
        res *= (n - k + i);
        res /= i;
    }

    return res;
}

// n! - n factorial
int factorial(int n) {
    int res = 1;

    for (int i = 2; i <= n; i++) {
        res *= i;
    }

    return res;
}

// gcd of a and b (a,b must be >= and cannot both be 0)
int gcd(int a, int b) {
    if (b > a) swap(a, b);

    while (b) {
      a %= b;
      swap(a, b);
    }

    return a;
}
