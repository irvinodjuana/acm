#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ll;

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

string soln(int p, int q, int s) {
    for (int x = p; x <= s; x += p) {
        if (x % q == 0) return "yes";
    }

    return "no";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Code
    int p, q, s;
    cin >> p >> q >> s;

    cout << soln(p,q,s) << endl;
    
    cout.flush();
    return 0;
}