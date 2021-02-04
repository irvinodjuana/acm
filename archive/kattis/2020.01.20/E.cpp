#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;

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

ull soln(int d, vector<int>& a) {
    unordered_map<int,ull> divs;

    for (int num : a) {
        divs[num / d]++;
    }

    ull pairs = 0;

    for (auto& p : divs) {
        ull n = p.second;
        pairs += (n * (n-1)) / 2;
    }

    return pairs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Code
    int n, d;
    cin >> n >> d;

    vector<int> a;
    read_array(a, n);

    cout << soln(d, a) << "\n";
    
    cout.flush();
    return 0;
}