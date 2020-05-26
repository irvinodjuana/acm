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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int tests;
    // cin >> tests;

    // REP(tt, 0, tests) {
        // code here
        int n;
        cin >> n;
        int even, odd, count_even = 0, count_odd = 0;
        int num;
        REP(i, 0, n) {
            cin >> num;
            if (num % 2 == 0) {
                even = i;
                count_even++;
            } else {
                odd = i;
                count_odd++;
            }
        }
        if (count_even == 1) {
            cout << even+1 << "\n";
        } else {
            cout << odd+1 << "\n";
        }
    // }

    
    cout.flush();
    return 0;
}