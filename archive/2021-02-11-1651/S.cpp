#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
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

void soln(int n, int m, vector<vector<char>>& grid) {
    for (int j = 0; j < m; j++) {
        int lastBlock = n;
        int applesBelow = 0;

        for (int i = n-1; i >= 0; i--) {
            if (grid[i][j] == '#') {
                lastBlock = i;
                applesBelow = 0;
            } else if (grid[i][j] == 'o') {
                swap(grid[i][j], grid[lastBlock - 1 - applesBelow][j]);
                applesBelow++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j];
        }
    }

    soln(n, m, grid);
    
    cout.flush();
    return 0;
}