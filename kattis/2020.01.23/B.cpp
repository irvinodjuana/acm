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

vector<string> soln(int n, vector<string>& names, vector<double>& leg1, vector<pair<double,int>>& leg2) {
    double best = 1e9;
    vector<int> bestRunners;

    sort(leg2.begin(), leg2.end());

    for (int i = 0; i < n; i++) {
        double curr = leg1[i];
        vector<int> runners = {i};

        for (auto [time, j] : leg2) {
            if (j != i) {
                curr += time;
                runners.push_back(j);
            }
            if (runners.size() == 4) {
                break;
            }
        }

        if (curr < best) {
            best = curr;
            bestRunners = runners;
        }
    }

    vector<string> res;
    for (int i : bestRunners) res.push_back(names[i]);

    cout << best << endl;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Code
    int n;
    cin >> n;
    vector<string> names(n);
    vector<double> leg1(n);
    vector<pair<double,int>> leg2(n);

    for (int i = 0; i < n; i++) {
        string name;
        double l1, l2;
        cin >> name >> l1 >> l2;
        names[i] = name;
        leg1[i] = l1;
        leg2[i] = {l2, i};
    }

    auto res = soln(n, names, leg1, leg2);

    for (auto s : res) {
        cout << s << "\n";
    }
    
    cout.flush();
    return 0;
}