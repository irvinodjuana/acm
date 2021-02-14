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

constexpr ll MOD = 10e9 + 7;

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
        res %= MOD;
    }

    return res;
}

ll solve(string s, int n) {
    ll res;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
    }

    
    cout.flush();
    return 0;
}