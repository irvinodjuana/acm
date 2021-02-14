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

void read_array(vector<int> & v, int n) {
    int num;
    while (n--) {
        cin >> num;
        v.push_back(num);
    }
}

int rook_moves(vector<pair<int,int>>& positions) {
    unordered_set<int> rows;
    unordered_map<int,int> row2col;
    unordered_map<int,int> col2row;

    for (auto& pos : positions) {
        if (pos.first == pos.second) continue;

        rows.insert(pos.first);
        row2col[pos.first] = pos.second;
        col2row[pos.second] = pos.first;
    }

    unordered_set<int> visited;
    int cycles = 0;

    for (int row : rows) {
        if (visited.count(row)) continue;
        visited.insert(row);

        int i = row;
        int j = row2col[row];

        unordered_set<int> seen;
        seen.insert(i);

        while (col2row.count(i)) {
            j = i;
            i = col2row[j];

            if (seen.count(i)) {
                cycles++;
                seen.insert(i);
                break;
            }

            seen.insert(i);
            visited.insert(i);
        }
    }

    return rows.size() + cycles;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> positions;

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            positions.push_back({x, y});
        }

        cout << rook_moves(positions) << endl;
    }

    
    cout.flush();
    return 0;
}