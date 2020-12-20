#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef long long ll;
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

ll solve(vector<pair<int,int>>& vtors) {
    map<pair<int,int>, ll> allSums;
    int ans = 0;

    for (auto vtor : vtors) {
        int x = vtor.first;
        int y = vtor.second;

        if (allSums.count({-x, -y})) {
            ans += allSums[{-x, -y}];
        }

        set<pair<int,int>> newSums;
        newSums.insert({x, y});

        for (auto& p : allSums) {
            pair<int,int> sum = p.first;
            newSums.insert({x + sum.first, y + sum.second});
        }

        for (auto& sum : newSums) {
            allSums[sum]++;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int,int>> vtors;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        vtors.push_back({x, y});
    }

    cout << solve(vtors) << endl;

    
    cout.flush();
    return 0;
}