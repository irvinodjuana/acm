#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;

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

int bin_search(int n, vector<int>& end, int val) {
    int lo = 0;
    int hi = n-2;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (end[mid] <= val && end[mid+1] > val) return mid;
        else if (end[mid] > val) hi = mid-1;
        else lo = mid+1;
    }

    return -1;
}

ull soln(int n, vector<int>& end, vector<int>& start, vector<int>& fun, vector<int>& wait) {
    vector<ull> dp(n, 0);
    dp[0] = fun[0];

    for (int i = 1; i < n; i++) {
        int j = bin_search(n, end, start[i]);
        ull incr = fun[i] + ((j >= 0 && j < n) ? dp[j] : 0);
        dp[i] = max(dp[i-1], incr);

        // printf("%d: %d, %llu\n", i, j, dp[i]);
    }

    return dp[n-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Code
    int n;
    cin >> n;
    vector<vector<int>> v;

    for (int i = 0; i < n; i++) {
        int t, f, w;
        cin >> t >> f >> w;
        v.push_back({t+w, t, f, w});
    }

    sort(v.begin(), v.end());

    vector<int> end;
    vector<int> start;
    vector<int> fun;
    vector<int> wait;

    for (vector<int>& vec : v) {
        end.push_back(vec[0]);
        start.push_back(vec[1]);
        fun.push_back(vec[2]);
        wait.push_back(vec[3]);
    }
    
    cout << soln(n, end, start, fun, wait) << "\n";
    
    cout.flush();
    return 0;
}