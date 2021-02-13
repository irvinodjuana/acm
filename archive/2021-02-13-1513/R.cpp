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

    // init dp array
    vector<vector<ull>> dp(81, vector<ull>(10, 0));
    
    for (int i = 1; i <= 80; i++) {
        dp[i][9] = 1;
        for (int j = 8; j >= 0; j--) {
            dp[i][j] = dp[i][j+1] + dp[i-1][j];
        }
    }

    int T;
    cin >> T;
    vector<string> output;

    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> num(n);
        bool isramp = true;

        // check if ramp
        for (int i = 0; i < n; i++) {
            num[i] = (s[i] - '0');
            if (i > 0 && num[i] < num[i-1]) {
                isramp = false;
                break;
            }
        }

        if (!isramp) {
            output.push_back("-1");
            continue;       
        }

        ull total = 0;

        // find num of ramp nums < num
        for (int i = 0; i <= n-1; i++) {
            int prev = (i == 0) ? 0 : num[i-1];
            // printf("i: %d, prev %d, num[i]-1: %d\n", i, prev, (num[i]-1));
            for (int j = prev; j <= num[i]-1; j++) {
                // printf("%s - adding [%d](%d) = %llu\n", s.c_str(), j, n-i, dp[n-i][j]);
                total += dp[n-i][j];
            }
        }

        output.push_back(to_string(total));
    }

    for (string s : output) {
        cout << s << "\n";
    }
    
    cout.flush();
    return 0;
}