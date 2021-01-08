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

bool mountain(vector<int>& a, int i, int n) {
    if (i <= 0 || i >= n-1) return false;
    return a[i-1] < a[i] && a[i+1] < a[i];
}

bool valley(vector<int>& a, int i, int n) {
    if (i <= 0 || i >= n-1) return false;
    return a[i-1] > a[i] && a[i+1] > a[i];
}

bool mountain_or_valley(vector<int>& a, int i) {
    return mountain(a, i, a.size()) || valley(a, i, a.size());
}

int soln(vector<int>& a, int n) {
    int totalint = 0;
    int bestred = 0;

    for (int i = 1; i < n-1; i++) {
        if (mountain_or_valley(a, i)) totalint++;
        int partial = (int) mountain_or_valley(a, i-1) + (int) mountain_or_valley(a, i) + (int) mountain_or_valley(a, i+1);
        int prev = a[i];
        a[i] = a[i-1];
        int mvleft = mountain_or_valley(a, i+1);
        a[i] = a[i+1];
        int mvright = mountain_or_valley(a, i-1);
        a[i] = prev;

        bestred = max(bestred, partial - min(mvleft, mvright));
    }

    return totalint - bestred;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        int n;
        cin >> n;
        vector<int> v;
        read_array(v, n);
        cout << soln(v, n) << endl;
    }

    
    cout.flush();
    return 0;
}