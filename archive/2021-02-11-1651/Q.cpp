#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

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

ull soln(int n, int k, vector<int>& t) {
    priority_queue<ull, vector<ull>, greater<ull> > pq;
    ull time = 0;
    ull penalty = 0;
    int i;

    for (i = 0; i < k; i++) {
        pq.push(t[i]);
    }

    while (!pq.empty()) {
        ull ti = pq.top();
        // printf("%llu\n", ti);
        pq.pop();

        time += ti;
        penalty += time;

        if (i < n) {
            pq.push(t[i++]);
        }
    }

    return penalty;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int n, k;
    cin >> n >> k;
    vector<int> t;
    read_array(t, n);
    
    cout << soln(n, k, t) << endl;

    
    cout.flush();
    return 0;
}