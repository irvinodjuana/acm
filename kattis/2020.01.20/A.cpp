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

int soln(int x, int y) {
    if (x > 0) {
        return (y > 0) ? 1 : 4;
    } else {
        return (y > 0) ? 2 : 3;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Code
    int x, y;
    cin >> x;
    cin >> y;

    printf("%d\n", soln(x,y));
    
    cout.flush();
    return 0;
}