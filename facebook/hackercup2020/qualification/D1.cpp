#include <bits/stdc++.h>
using namespace std;

// shortened types
typedef long long int ll;

#define MAX_VAL LLONG_MAX


vector<int> read_vector(ifstream& fin, int N) {
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        fin >> C[i];
    }
    return C;
}

ll solution(vector<int>& C, int N, int M) {
    vector<int> cities;
    vector<ll> costs;

    cities.push_back(0);
    costs.push_back(0);

    int start = 0;

    for (int i = 1; i < N-1; i++) {
        if (C[i] != 0) {
            cities.push_back(i);
            costs.push_back(C[i]);
        }
    }

    cities.push_back(N-1);
    costs.push_back(0);

    int n = cities.size();
    vector<ll> minCosts(n, MAX_VAL);
    minCosts[0] = 0;

    for (int i = 0; i < n; i++) {
        if (minCosts[i] == MAX_VAL) return -1; // city unreachable

        int j = i + 1;
        while (j < n && cities[j] <= cities[i] + M) {
            minCosts[j] = min(minCosts[j], minCosts[i] + costs[i]);
            j++;
        }
    }

    return minCosts[n-1];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("D1_input.txt");
    ofstream fout("D1_output.txt");

    int tests;
    fin >> tests;

    for (int t = 0; t < tests; t++) {
        // code here
        int N, M;
        fin >> N >> M;
        vector<int> C = read_vector(fin, N);

        ll soln = solution(C, N, M);
        
        fout << "Case #" << t+1 << ": " << soln << "\n";
    }

    fin.close();
    fout.close();
    
    cout.flush();
    return 0;
}