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

string solution(vector<int>& c, int n) {
    unordered_set<int> combos;
    combos.insert(0);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        unordered_set<int> temp;
        sum += c[i];

        for (int comb : combos) {
            temp.insert(comb + c[i]);
        }

        for (int comb : temp) {
            combos.insert(comb);
        }
    }

    if (sum % 2 == 1) return "NO";
    return (combos.count(sum / 2)) ? "YES" : "NO";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        int n;
        vector<int> c;
        cin >> n;
        read_array(c, n);
        cout << solution(c, n) << endl;
    }

    
    cout.flush();
    return 0;
}