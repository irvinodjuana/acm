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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    double x, y;
    cin >> x >> y;

    double a = y * log(x), b = x * log(y);
    if (abs(a-b) < 1e-9) {
        cout << "=";
    } else if (a < b) {
        cout << "<";
    } else {
        cout << ">";
    }

    cout << "\n";

    
    cout.flush();
    return 0;
}