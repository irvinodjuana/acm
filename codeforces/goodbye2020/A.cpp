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

int num_areas(vector<int>& x, int n) {
    unordered_set<int> areas;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            areas.insert(x[j] - x[i]);
        }
    }

    return areas.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        vector<int> x;
        int n;
        cin >> n;
        read_array(x, n);
        printf("%d\n", num_areas(x, n));
    }

    
    cout.flush();
    return 0;
}