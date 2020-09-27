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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        int n, m;
        cin >> n >> m;

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            string s;
            cin >> s;
            if (s[m-1] == 'R') ans++; 
        }

        string s;
        cin >> s;

        for (int i = 0; i < m - 1; i++) {
            if (s[i] == 'D') ans++;
        }

        cout << ans << "\n";
    }

    
    cout.flush();
    return 0;
}