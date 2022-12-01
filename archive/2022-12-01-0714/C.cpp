#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// common utils
vector<int> read_vector(int n);
vector<vector<char>> read_matrix(int n, int m);
bool in_bounds(int i, int j, int n, int m);
void print_vector(vector<int> v);

int choose(int n, int k);
int factorial(int n);
int gcd(int a, int b);


// solution code
void reverse(vector<int>& A, int i, int j) {
    while (i < j) {
        swap(A[i++], A[j--]);
    }
}

string soln(int N, int C) {
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = i+1;
    }

    C -= (N-1);
    if (C < 0) return "IMPOSSIBLE";

    for (int i = 0; i < N-1; i++) {
        int r = min(C, N-1-i);
        C -= r;
        reverse(A, i, i+r);
    }

    if (C > 0) return "IMPOSSIBLE";

    string s = to_string(A[0]);
    for (int i = 1; i < N; i++) {
        s += " ";
        s += to_string(A[i]);
    }

    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int T;
    cin >> T;
    vector<string> output;
    
    for (int t = 0; t < T; t++) {
        int N, C;
        cin >> N >> C;
        output.push_back(soln(N, C));
    }

    for (int i = 0; i < T; i++) {
        printf("Case #%d: %s\n", i+1, output[i].c_str());
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
