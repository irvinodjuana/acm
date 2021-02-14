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

int findRoot(int L) {
    int i = sqrt(L);
    if (i * i == L) return i;
    return i + 1;
}

string solve(string& s) {
    int L = s.size();
    int k = findRoot(L);
    string ans = "";

    for (int mod = 0; mod < k; mod++) {
        for (int div = k - 1; div >= 0; div--) {
            int idx = k * div + mod;
            if (idx < L) {
                ans += s[idx];
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        string s;
        cin >> s;

        cout << solve(s) << "\n";
    }

    
    cout.flush();
    return 0;
}