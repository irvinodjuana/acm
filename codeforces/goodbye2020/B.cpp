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



int get_diversity(vector<int>& notes, int n) {
    unordered_map<int, int> note_count;
    unordered_set<int> orig_notes;

    for (int note : notes) {
        note_count[note]++;
        orig_notes.insert(note);
    }

    vector<int> orig(orig_notes.begin(), orig_notes.end());
    sort(orig.begin(), orig.end());

    for (int note : orig) {
        if (note_count[note] >= 2) {
            note_count[note+1]++;
        }
    }

    int total = 0;

    for (auto p : note_count) {
        if (p.second > 0) total++;
    }

    return total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        vector<int> x;
        int n;
        cin >> n;
        read_array(x, n);
        cout << get_diversity(x, n) << endl;
    }

    
    cout.flush();
    return 0;
}