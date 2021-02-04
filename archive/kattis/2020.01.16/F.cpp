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

double soln(int k, int w, int l) {
    double sum = 0;

    for (int i = 1; i <= k-1; i++) {
        sum += (1 << i);
    }

    sum += 0.5 + (1 << (k - 1));

    double tanAlpha = (1.0 * l / (sum * w));
    return atan(tanAlpha) * 180.0 / M_PI;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, w, l;
    cin >> k >> w >> l;

    printf("%.8f\n", soln(k, w, l));
    
    cout.flush();
    return 0;
}