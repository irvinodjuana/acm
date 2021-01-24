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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Code
    int n;
    cin >> n;

    double qaly = 0.0;
    
    for (int i = 0; i < n; i++) {
        double q, l;
        cin >> q >> l;
        qaly += (q * l);
    }

    printf("%.4f\n", qaly);
    
    cout.flush();
    return 0;
}