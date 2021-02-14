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
    string s;
    cin >> s;
    unordered_map<char,int> m;

    for (char c : s) {
        m[c]++;
    }

    vector<int> v;

    for (auto p : m) {
        v.push_back(p.second);
    }
    
    sort(v.rbegin(), v.rend());

    int res;
    if (v.size() >= 2) {
        res = s.size() - v[0] - v[1];
    } else {
        res = 0;
    }

    printf("%d\n", res);
    
    
    cout.flush();
    return 0;
}