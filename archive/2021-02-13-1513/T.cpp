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


long replace(string s, char digit) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') s[i] = digit;
    }
    return stol(s);
}

// solution code
int soln(string& s) {
    string num1, num2, num3;
    char op;
    unordered_set<char> opset = {'+', '-', '*'};

    string token = "";
    token += s[0];
    int i = 1;

    // num1
    while (!opset.count(s[i])) token += s[i++];
    num1 = token;
    token = "";
    op = s[i++];

    // num2
    while (s[i] != '=') token += s[i++];
    num2 = token;
    
    // num3
    num3 = s.substr(i+1);


    if (op == '+') {
        for (char c = '0'; c <= '9'; c++) {
            if (replace(num1, c) + replace(num2, c) == replace(num3, c)) {
                return c - '0';
            }
        }
    } else if (op == '-') {
        for (char c = '0'; c <= '9'; c++) {
            if (replace(num1, c) - replace(num2, c) == replace(num3, c)) {
                return c - '0';
            }
        }
    } else if (op == '*') {
        for (char c = '0'; c <= '9'; c++) {
            if (replace(num1, c) * replace(num2, c) == replace(num3, c)) {
                return c - '0';
            }
        }
    }


    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int tests;
    cin >> tests;
    vector<string> input;

    for (int i = 0; i < tests; i++) {
        string s;
        cin >> s;
        input.push_back(s);
    }

    for (string s : input) {
        cout << soln(s) << endl;
    }
    
    cout.flush();
    return 0;
}