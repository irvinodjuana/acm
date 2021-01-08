#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
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

ull soln(vector<int>& nums, int n) {
    vector<ull> dp(n, 0);
    ull best = 0;

    for (int i = n-1; i >= 0; i--) {
        dp[i] = nums[i];

        if (i + nums[i] < n) {
            dp[i] += dp[i + nums[i]];
        }

        best = max(best, dp[i]);
    }

    return best;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        int n;
        vector<int> nums;
        cin >> n;
        read_array(nums, n);

        cout << soln(nums, n) << endl;
    }

    
    cout.flush();
    return 0;
}