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

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        int a, b, c = 0;
        cin >> a >> b;
        while (a > 0 && b > 0) {
            if (a == 1 && b == 1) {
                break;
            } else if ( a >= b ) {
                a -= 2;
                b -= 1;
                c++;
            } else {
                b -= 2;
                a -= 1;
                c++;
            }
        }

        cout << c << "\n";
    }

    
    cout.flush();
    return 0;
}