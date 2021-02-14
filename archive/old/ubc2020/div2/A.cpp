#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

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

ll choose(ll n, ll k) {
    ll res = 1;
    if (n - k < k) k = n - k;

    for (ll i = 1; i <= k; i++) {
        res *= (n - k + i);
        res /= i;
    }

    return res;
}

bool solve(int R, int S, int X, int Y, int W) {
    double p = (1.0 * S - R + 1) / S;
    double P = 0;

    for (int i = X; i <= Y; i++) {
        P += choose(Y, i) * pow(p, i) * pow(1 - p, 1.0 * Y - i);
    }

    return W * P > 1.0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; test++) {
        // code here
        int R, S, X, Y, W;
        cin >> R >> S >> X >> Y >> W;

        cout << (solve(R, S, X, Y, W) ? "yes" : "no") << "\n";
    }

    
    cout.flush();
    return 0;
}