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
    int T;
    cin >> T;

    vector<vector<int>> output;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        // init L1 and L2 lists
        vector<string> L1;
        for (int i = 0; i < n; i++) {
            string x;
            cin >> x;
            L1.push_back(x);
        }

        vector<string> L2;
        for (int i = 0; i< n; i++) {
            string x;
            cin >> x;
            L2.push_back(x);
        }

        vector<int> results;
        unordered_set<string> miss1;
        unordered_set<string> miss2;
        int runsize = 1;

        // count sets
        for (int i = 0; i < n; i++) {
            string l1 = L1[i];
            string l2 = L2[i];

            if (l1 != l2) {
                if (miss1.count(l1)) {
                    miss1.erase(l1);
                } else {
                    miss2.insert(l1);
                }

                if (miss2.count(l2)) {
                    miss2.erase(l2);
                } else {
                    miss1.insert(l2);
                }
            }

            if (miss1.empty()) {
                results.push_back(runsize);
                runsize = 1;
            } else {
                runsize++;
            }
        }

        output.push_back(results);
    }

    for (auto v : output) {
        for (int i = 0; i < v.size() - 1; i++) {
            printf("%d ", v[i]);
        }
        printf("%d\n", v.back());
    }
    
    cout.flush();
    return 0;
}