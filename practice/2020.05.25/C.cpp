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

void read_array(vector<int> & v, int n) {
    int num;
    while (n--) {
        cin >> num;
        v.push_back(num);
    }
}

void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vi A;
    read_array(A, n);
    vi diff(n);

    REP (i, 1, n) {
        diff[i] = A[i] - A[i-1];
    }

    sort(diff.begin(), diff.end());
    // print_vector(diff);

    int res = 0, i = 1;
    while (n > k) {
        res += diff[i];
        n--;
        i++;
    }

    cout << res << "\n";

    
    cout.flush();
    return 0;
}