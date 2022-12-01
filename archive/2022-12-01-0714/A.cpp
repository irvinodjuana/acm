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
int soln(vector<int>& A) {
    int n = A.size();
    int res = 0;

    for (int i = 0; i < n-1; i++) {
        int j = i;
        for (int k = i; k < n; k++) {
            if (A[k] < A[j]) {
                j = k;
            }
        }
        res += (j-i+1);
        int k = i;
        while (k < j) {
            swap(A[k++], A[j--]);
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int T;
    cin >> T;
    vector<int> output;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<int> A = read_vector(N);
        output.push_back(soln(A));
    }

    for (int i = 0; i < T; i++) {
        printf("Case #%d: %d\n", i+1, output[i]);
    }
    
    cout.flush();
    return 0;
}