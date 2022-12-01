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

    vector<int> nums;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    sort(nums.begin(), nums.end());

    ull count = 0;

    for (int r = 0; r < n; r++) {
        for (int l = 0; l <= r-2; l++) {
            int m = l+1;
            while ((ull) nums[l] + (ull) nums[m] <= (ull) nums[r]) m++;

            int n = r - m;

            ull res = pow(2, n);
            res -= 1;

            if (n >= 1) {
                count += res;
            }
        }
    }

    cout << count << "\n";
    
    cout.flush();
    return 0;
}