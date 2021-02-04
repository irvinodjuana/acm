#include <bits/stdc++.h>
using namespace std;

char solution(string& shards) {
    int countA = 0;
    int countB = 0;

    for (char& c : shards) {
        if (c == 'A') countA++;
        else countB++;
    }

    return (abs(countA - countB) == 1) ? 'Y' : 'N';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("input_alchemy.txt");
    ofstream fout("output_alchemy.txt");

    int tests;
    fin >> tests;

    for (int t = 0; t < tests; t++) {
        // code here
        int N;
        fin >> N;
        string shards;
        fin >> shards;

        fout << "Case #" << t+1 << ": " << solution(shards) << "\n";
    }

    fin.close();
    fout.close();
    
    cout.flush();
    return 0;
}