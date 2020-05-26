#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

// macros
#define um unordered_map
#define us unordered_set
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPI(i, a, b) for (int i = a; i <= b; i++)

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

    int tests;
    cin >> tests;

    REP(tt, 0, tests) {
        // code here
        int n;
        cin >> n;

        vector<int> A;
        um<int, int> counts;
        us<int> integers;
        read_array(A, n);

        REP(i, 0, n) {
            counts[A[i]]++;
            integers.insert(A[i]);
        }

        int res = 0;

        REP (i, 0, n) {
            int sum = A[i];
            REP (j, i + 1, n) {
                sum += A[j];
                if (integers.count(sum) == 1) {
                    integers.erase(sum);
                    res += counts[sum];
                }
            }
        }


        cout << res << "\n";


    }


    
    cout.flush();
    return 0;
}