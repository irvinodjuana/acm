#include <bits/stdc++.h>
using namespace std;

// shortened types
typedef long long int ll;

// macros
#define MAX_VAL LLONG_MAX


vector<int> read_vector(ifstream& fin, int N) {
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        fin >> C[i];
    }
    return C;
}

int solution(int N) {
    // solution here
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("input_file.txt");
    ofstream fout("output_file.txt");

    int tests;
    fin >> tests;

    for (int t = 0; t < tests; t++) {
        // code here
        int N;
        fin >> N;
        
        int soln = solution(N);

        fout << "Case #" << t+1 << ": " << soln << "\n";
    }

    fin.close();
    fout.close();
    
    cout.flush();
    return 0;
}