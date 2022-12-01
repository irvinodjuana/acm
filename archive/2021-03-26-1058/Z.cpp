#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// common utils

vector<vector<char>> read_matrix(int n, int m) {vector<vector<char>> grid(n, vector<char>(m));for (int i = 0; i < n; i++) {string s;cin >> s;for (int j = 0; j < m; j++) {grid[i][j] = s[j];}}return grid;}
bool in_bounds(int i, int j, int n, int m) {return i >= 0 && i < n && j >= 0 && j < m;}
void print_vector(vector<int> v) {for (int i = 0; i < v.size(); i++) {cout << v[i] << " ";}cout << "\n";}
vector<int> read_vector(int n) {vector<int> v;int num;while (n--) {cin >> num;v.push_back(num);}return v;}


// solution code


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int n;
    cin >> n;
    string s;
    cin >> s;

    int j = 0;

    for (int i = 1; i < n; i++) {
        if (j >= s.size()) break;
        string t;

        if (i >= 0 && i <= 9) {
            t = s[j];
            j++; 
        } else if (i >= 10 && i <= 99) {
            t = s.substr(j, 2);
            j += 2;
        } else {
            t = s.substr(j, 3);
            j += 3; 
        }

        if (stoi(t) != i) {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("%d\n", n);
    
    
    cout.flush();
    return 0;
}