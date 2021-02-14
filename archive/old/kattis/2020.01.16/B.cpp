#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

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


ull soln(int s, int p, int m, int n, vector<int>& t) {
    vector<ull> cost(n);
    int j = -1;

    for (int i = 0; i < n; i++) {
        while (j+1 < n && t[j+1] <= t[i]-m) j++;
        int s_cost = (i >= 1) ? s + cost[i-1] : s;
        int p_cost = (j >= 0) ? p + cost[j] : p;
        cost[i] = min(s_cost, p_cost);
    }

    return cost[n-1];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s, p, m, n;
    cin >> s >> p >> m >> n;
    vector<int> t;
    read_array(t, n);

    cout << soln(s, p, m, n, t) << "\n";

    cout.flush();
    return 0;
}