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
    int a, b;
    cin >> a >> b;

    if (a == 0 && b == 0) {
        printf("Not a moose\n");
    } else {
        string e = (a == b) ? "Even" : "Odd";
        int c = 2 * max(a, b);
        printf("%s %d\n", e.c_str(), c);
    }
    
    cout.flush();
    return 0;
}