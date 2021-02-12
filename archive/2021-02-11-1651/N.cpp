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


bool halfSumExists(vector<int>& v, int total) {
    if (total % 2 == 1) return false;
    unordered_set<int> sums;

    for (int num : v) {
        unordered_set<int> temp;
        temp.insert(num);

        for (int s : sums) temp.insert(s + num);
        for (int s : temp) sums.insert(s);

        if (sums.count(total / 2)) return true;
    }

    return false;
}


void subset_search(int m, vector<int>& p, int i, vector<int>& sub, unordered_set<int>& W) {
    if (i == m) {
        int total = 0;
        for (int i : sub) total += i;
        if (W.count(total)) return;
        if (halfSumExists(sub, total)) W.insert(total);

        return;
    }

    // subset search - recursive call w/o element p[i], then with elem p[i]
    subset_search(m, p, i+1, sub, W);
    sub.push_back(p[i]);
    subset_search(m, p, i+1, sub, W);
    sub.pop_back();
}


vector<int> soln(int n, int m, vector<int>& b, vector<int>& p) {
    // search through subsets of p -> fill set W with all possible plate weights
    unordered_set<int> W;
    vector<int> subset;
    subset_search(m, p, 0, subset, W);

    // find all combos of plate weights + barbell weights
    unordered_set<int> all(b.begin(), b.end());

    for (int wb : b) {
        for (int w : W) {
            all.insert(wb + w);
        }
    }

    // turn into list and sort
    vector<int> res(all.begin(), all.end());
    sort(res.begin(), res.end());

    return res;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int n, m;
    cin >> n >> m;

    auto b = read_vector(n);
    auto p = read_vector(m);

    auto res = soln(n, m, b, p);
    for (int r : res) {
        printf("%d\n", r);
    }
    
    cout.flush();
    return 0;
}