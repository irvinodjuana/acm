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

void solve(vector<int>& nums, int n, int T) {
    unordered_set<int> whites;
    vector<int> ans(n, 0);
    int lastHalf = 0;

    for (int i = 0; i < n; i++) {
        if (T == nums[i] * 2) {
            ans[i] = lastHalf;
            lastHalf = !lastHalf;
        } else if (whites.count(T - nums[i])) {
            ans[i] = 1;
        } else {
            whites.insert(nums[i]);
        }
    }
    
    print_vector(ans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        int n, T;
        cin >> n >> T;
        vector<int> nums;
        read_array(nums, n);

        solve(nums, n, T);
    }

    
    cout.flush();
    return 0;
}