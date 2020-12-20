#include <bits/stdc++.h>
using namespace std;

constexpr int H = 1;
constexpr int V = 0;

unordered_map<int,int> memo;

int P(int N, int M, int player) {
    if (N == 1 && M == 1) return !player;
    if (N == 1 && M > 1) return V;
    if (N > 1 && M == 1) return H;

    int key = N * 10000 + M * 10 + player;
    
    if (!memo.count(key)) {
        if (player == H) {
            int winner = V;
            for (int i = 1; i <= N / 2; i++) {
                if (P(i, M, V) == H && P(N - i, M, V) == H) {
                    winner = H;
                    break;
                }
            }
            memo[key] = winner;
        } else {
            int winner = H;
            for (int j = 1; j <= M / 2; j++) {
                if (P(N, j, H) == V && P(N, M - j, H) == V) {
                    winner = V;
                    break;
                }
            }
            memo[key] = winner;
        }
    }

    return memo[key];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    for (int i = 0; i < tests; i++) {
        int N, M;
        string player;
        cin >> M >> N >> player;

        int p = (player == "Harry");
        int winner = P(N, M, p);

        string suffix = (winner == p) ? " can win" : " cannot win";

        cout << player + suffix << "\n";
    }

    
    cout.flush();
    return 0;
}