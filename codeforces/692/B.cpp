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

bool is_fair(ull num) {
    bitset<10> digits;

    ull numcopy = num;

    while (numcopy > 0) {
        digits[numcopy % 10] = true;
        numcopy /= 10;
    }

    for (int i = 1; i <= 9; i++) {
        if (digits[i] && (num % i != 0)) return false;
    }

    return true;
}

ull find_next_fair(ull num) {
    while (!is_fair(num)) {
        num++;
    }

    return num;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        ull num;
        cin >> num;
        cout << find_next_fair(num) << endl;
    }

    
    cout.flush();
    return 0;
}