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

bool is_bad(string& s) {
    int n = s.size();
    int i = n - 1;

    while (i >= 0 && s[i] == ')') {
        i--;
    }
    
    return (n - i - 1) > (i + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        string s;
        int n;
        cin >> n;
        cin >> s;

        if (is_bad(s)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    
    cout.flush();
    return 0;
}