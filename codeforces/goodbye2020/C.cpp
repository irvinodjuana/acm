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

int no_palindromes(string s) {
    set<pair<int,int>> pairs;
    unordered_map<int,int> idxcount;

    int n = s.size();

    for (int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) {
            pairs.insert({i, i+1});
            idxcount[i]++;
            idxcount[i+1]++;
        }
        if (i < n-2 && s[i] == s[i+2]) {
            pairs.insert({i, i+2});
            idxcount[i]++;
            idxcount[i+2]++;
        }
    }

    unordered_set<int> changeset;

    for (auto& [i, j] : pairs) {
        if (!changeset.count(i) && !changeset.count(j)) {
            if (idxcount[i] > idxcount[j]) {
                changeset.insert(i);
            } else {
                changeset.insert(j);
            }
        }

        idxcount[i]--;
        idxcount[j]--;
    }

    return changeset.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        string s;
        cin >> s;
        cout << no_palindromes(s) << endl;
    }

    
    cout.flush();
    return 0;
}