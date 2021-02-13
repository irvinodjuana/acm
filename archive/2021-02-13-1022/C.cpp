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
    bitset<8> row;
    bitset<8> col;
    bitset<15> dgd;
    bitset<15> dgu;

    // code
    auto grid = read_matrix(8, 8);
    int qcount = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] == '.') continue;
            qcount++;
            if (row[i] || col[j] || dgd[7+i-j] || dgu[i+j]) {
                cout << "invalid\n";
                return 0;
            }
            row[i] = col[j] = dgd[7+i-j] = dgu[i+j] = true;
        }
    }
    
    if (qcount != 8) cout << "invalid\n";
    else cout << "valid\n";
    
    cout.flush();
    return 0;
}