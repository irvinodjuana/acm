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
    vector<pair<string,string>> v;

    for (int i = 0; i < n; i++) {
        string first, last;
        cin >> first >> last;
        v.push_back({last, first});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        printf("%s %s\n", v[i].second.c_str(), v[i].first.c_str());
    }
    
    
    cout.flush();
    return 0;
}