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

string solve(string s) {
    bitset<26> present;

    for (char l : s) {
        if (isalpha(l)) {
            char c = tolower(l);
            present[c - 'a'] = true;
        }
    }

    string missing = "";

    for (char c = 'a'; c <= 'z'; c++) {
        if (!present[c - 'a']) {
            missing += c;
        }
    }

    return (missing.size()) ? "missing " + missing : "pangram"; 
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string t;
    getline(cin, t);
    int tests = stoi(t);

    vector<string> strs;

    for (int test = 0; test < tests; test++) {
        string s;
        getline(cin, s);
        cout << solve(s) << endl;
    }

    for (string& s : strs) {
        
    }

    
    cout.flush();
    return 0;
}