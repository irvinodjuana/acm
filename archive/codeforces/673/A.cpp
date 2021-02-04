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

int solve(vector<int>& candies, int n, int k) {
    int idx = 0;
    int lo = candies[0];

    for (int i = 1; i < n; i++) {
        if (candies[i] < lo) {
            idx = i;
            lo = candies[i];
        }
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
        if (i != idx) {
            res += (k - candies[i]) / lo;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        int n, k;
        cin >> n >> k;

        vector<int> nums;
        read_array(nums, n);

        cout << solve(nums, n, k) << endl;
    }

    
    cout.flush();
    return 0;
}