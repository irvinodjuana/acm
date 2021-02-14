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

int soln(vector<int>& v, int n) {
    sort(v.begin(), v.end());

    int x = v[0] + v[n-1];

    for (int i = 0; i < n/2; i++) {
        x = min(x, v[i] + v[n-1-i]);
    }

    return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Code
    int n;
    cin >> n;
    vector<int> v;
    read_array(v, n);

    printf("%d\n", soln(v, n));
    
    
    
    cout.flush();
    return 0;
}