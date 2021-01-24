#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
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

void read_array(vector<int> & v, int n) {
    int num;
    while (n--) {
        cin >> num;
        v.push_back(num);
    }
}

int soln(int n, int k, vector<pair<int,int>>& start, vector<pair<int,int>>& end, set<int>& nums) {
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int si = 0;
    int se = 0;

    unordered_set<int> friends;
    int best = 0;

    for (int i : nums) {
        int j = i + k;

        while (si < n && start[si].first <= j) {
            friends.insert(start[si].second);
            si++;
        }

        while (se < n && end[se].first < i) {
            friends.erase(end[se].second);
            se++;
        }

        best = max(best, (int) friends.size());
    }

    return best;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> start;
    vector<pair<int,int>> end;
    set<int> nums;

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        start.push_back({s, i});
        end.push_back({e, i});
        nums.insert(s);
        nums.insert(e);
    }

    printf("%d\n", soln(n, k, start, end, nums));

    
    cout.flush();
    return 0;
}