#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ll;
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

ll factorialmodp(ll n, ll p) {
    ll ans = 1;

    for (ll i = 2; i <= n; i++) {
        if ((ans * i) % p == 0) {
          ans = (ans * i);
        } else {
          ans = (ans * i) % p;
        }
    }
    return ans;
}

ll pow2modp(ll n, ll p) {
    ll ans = 1;

    for (ll i = 0; i < n; i++) {
        ans = (ans * 2) % p;
    }

    return ans % p;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll p = 1000000007;
    ll n;
    cin >> n;

    ll ans = (factorialmodp(n, p) - pow2modp(n-1, p)) % p;
    cout << ans << "\n";
    
    cout.flush();
    return 0;
}