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

string soln(vector<int>& row1, vector<int>& row2, int n) {
    int out1 = 0;
    int out2 = 0;

    for (int i = 0; i < n; i++) {
        int r1 = row1[i];
        int r2 = row2[i];
        if (!out1 && !out2) {
            if (r1 && r2) {
                out1 = 0; out2 = 0;
            } else if (!r1 && r2) {
                out1 = 0; out2 = 1;
            } else if (r1 && !r2) {
                out1 = 1; out2 = 0;
            } else /* !r1 && !r2 */ {
                out1 = 0; out2 = 0;
            }
        } else if (!out1 && out2) {
            if (r1 && r2) {
                out1 = 1; out2 = 0;
            } else if (!r1 && r2) {
                out1 = 0; out2 = 0;
            } else if (r1 && !r2) {
                return "NO";
            } else /* !r1 && !r2 */ {
                return "NO";
            }
        } else if (out1 && !out2) {
            if (r1 && r2) {
                out1 = 0; out2 = 1;
            } else if (!r1 && r2) {
                return "NO";
            } else if (r1 && !r2) {
                out1 = 0; out2 = 0;
            } else /* !r1 && !r2 */ {
                return "NO";
            }
        } else /* out1 && out2  */ {
            // not possible
        }
    }

    if (out1 || out2) return "NO";
    return "YES";
    
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
        vector<int> row1(n, 1);
        vector<int> row2(n, 1);

        for (int i = 0; i < m; i++) {
            int r, c;
            cin >> r >> c;
            
            if (r == 1) row1[c-1] = 0;
            else if (r == 2) row2[c-1] = 0;
        }

        cout << soln(row1, row2, n) << endl;
    }

    
    cout.flush();
    return 0;
}