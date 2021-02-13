#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// common utils

vector<vector<char>> read_matrix(int n, int m) {vector<vector<char>> grid(n, vector<char>(m));for (int i = 0; i < n; i++) {string s;cin >> s;for (int j = 0; j < m; j++) {grid[i][j] = s[j];}}return grid;}
bool inBounds(int i, int j, int n, int m) {return i >= 0 && i < n && j >= 0 && j < m;}
void print_vector(vector<int> v) {for (int i = 0; i < v.size(); i++) {cout << v[i] << " ";}cout << "\n";}
vector<int> read_vector(int n) {vector<int> v;int num;while (n--) {cin >> num;v.push_back(num);}return v;}


// solution code


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int n;
    string s;
    getline(cin, s);
    n = stoi(s);

    string simon = "Simon says";
    vector<string> output;

    for (int i = 0; i < n; i++) {
        getline(cin, s);
        if (s.size() < simon.size()) continue;
        if (s.substr(0, simon.size()) == simon) {
            output.push_back(s.substr(simon.size()));
        }
    }

    for (auto s : output) {
        cout << s << endl;
    }
    
    cout.flush();
    return 0;
}