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

int soln(vector<int>& c, int n) {
    sort(c.begin(), c.end());

    int best = 0;

    for (int i = n-1; i >=0; i--) {
        if (c[i] >= n-i) {
            best = max(best, n-i);
        }
    }

    return best;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Code
    int n;
    cin >> n;
    vector<int> c;
    read_array(c, n);

    cout << soln(c, n) << endl;
    
    cout.flush();
    return 0;
}