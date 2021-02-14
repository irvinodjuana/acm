#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

// macros
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPI(i, a, b) for (int i = a; i <= b; i++)

void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

vector<int> read_array(int n) {
    vector<int> v;
    int num;
    while (n--) {
        cin >> num;
        v.push_back(num);
    }
    return v;
}

void printmap(unordered_map<int,int>& dict) {
    cout << "{ ";

    for (auto& p : dict) {
        cout << p.first << ":" << p.second << ", ";
    }

    cout << "}" << endl;
}

void solve(vector<int>& nums, int n) {
    vector<int> amazing(n, -1);

    map<int, vector<int>> locs;

    for (int i = 0; i < n; i++) {
        if (!locs.count(nums[i])) {
            locs[nums[i]].push_back(-1);
        }
        locs[nums[i]].push_back(i);
    }

    for (auto& p : locs) {
        p.second.push_back(n);

        vector<int>& idxs = p.second;
        int best = 0;

        for (int i = 1; i < idxs.size(); i++) {
            best = max(best, idxs[i] - idxs[i-1]);
        }

        for (int i = best - 1; i < n; i++) {
            if (amazing[i] != -1) break;
            amazing[i] = p.first;
        }
    }

    print_vector(amazing);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        int n;
        cin >> n;
        vector<int> nums = read_array(n);
        solve(nums, n);
    }

    
    cout.flush();
    return 0;
}