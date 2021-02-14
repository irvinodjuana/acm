#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ll;

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Code
    int n, m;
    cin >> n >> m;
    unordered_map<int,int> score;
    unordered_map<int,int> penalty;

    unordered_set<int> higher;

    for (int i = 0; i < m; i++) {
        int t, p;
        cin >> t >> p;
        score[t]++;
        penalty[t] += p;

        // printf("%d: %d, %d\n", t, score[t], penalty[t]);
        
        if (t == 1) {
            higher.clear();
            for (int s = 2; s <= n; s++) {
                if ((score[s] > score[1] || (score[s] == score[1] && penalty[s] < penalty[1]))) {
                    higher.insert(s);
                }
            }
            printf("%lu\n", higher.size() + 1);
            continue;
        }

        if (score[t] > score[1] || (score[t] == score[1] && penalty[t] < penalty[1])) {
            higher.insert(t);
        } else {
            higher.erase(t);
        } 

        printf("%lu\n", higher.size() + 1);
    }
    
    cout.flush();
    return 0;
}