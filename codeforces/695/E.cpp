#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

// macros
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REPI(i, a, b) for (int i = a; i <= b; i++)

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

 bool searchTree(vector<int>& a, int node, unordered_map<int, vector<int>>& children, int& ans, unordered_set<int>& vals) {
    if (!children.count(node)) {
        vals.insert(a[node-1]);
        return true;
    }

    unordered_set<int> valsL, valsR;
    bool drL = searchTree(a, children[node][0], children, ans, valsL);
    bool drR = searchTree(a, children[node][1], children, ans, valsR);

    valsL.merge(valsR);
    vals = valsL;
    bool ins = vals.count(a[node-1]);
    vals.insert(a[node-1]);

    bool dr = ins && drL && drR;
    if (dr) ans++;

    return dr;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a;
    read_array(a, n);
    unordered_map<int, vector<int>> children;
    unordered_set<int> hasParent;

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        children[a].push_back(b);
        hasParent.insert(b);
    }

    int root;

    for (int i = 1; i <= n; i++) {
        if (!hasParent.count(i)) {
            root = i;
            break;
        }
    }

    unordered_set<int> vals;
    int ans = 0;

    searchTree(a, root, children, ans, vals);
    cout << ans << endl;

    
    cout.flush();
    return 0;
}