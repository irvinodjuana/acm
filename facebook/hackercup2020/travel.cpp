#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<char>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "";
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

vector<char> string2vec(string& s) {
    vector<char> vec;
    for (auto& c : s) {
        vec.push_back(c);
    }
    return vec;
}

void print_matrix(vector<vector<char>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        print_vector(matrix[i]);
    }
}

vector<vector<char>> solution(int N, vector<char>& in, vector<char>& out) {
    vector<vector<char>> matrix(N, vector<char>(N, 'N'));
    vector<int> left(N);
    vector<int> right(N);

    left[0] = 0;

    for (int i = 1; i < N; i++) {
        if (out[i] == 'Y' && in[i-1] == 'Y') {
            left[i] = left[i-1];
        } else {
            left[i] = i;
        }
    }

    right[N-1] = N-1;

    for (int i = N-2; i >= 0; i--) {
        if (out[i] == 'Y' && in[i+1] == 'Y') {
            right[i] = right[i+1];
        } else {
            right[i] = i;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j >= left[i] && j <= right[i]) {
                matrix[i][j] = 'Y';
            }
        }
    }

    return matrix;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    for (int t = 0; t < tests; t++) {
        // code here
        int N;
        string I, O;
        cin >> N;
        cin >> I;
        cin >> O;
        vector<char> in = string2vec(I);
        vector<char> out = string2vec(O);

        vector<vector<char>> matrix = solution(N, in, out);
        
        cout << "Case #" << t+1 << ":\n";
        print_matrix(matrix);
    }

    
    cout.flush();
    return 0;
}