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

int main() {
    // solution code here

    // test type names
    ll a = 123456789;
    ll b = 987654321;
    cout << a*b << "\n";

    // test macros
    vector<pi> v; 
    v.PB(MP(1,2));
    v.PB(MP(3,4));
    cout << v[0].F + v[1].F << " " << v[0].S + v[1].S << "\n";

    REP (i, 1, 4) {
        cout << i;
    }
    cout << endl;
    REPI (i, 1, 4) {
        cout << i;
    }
    cout << endl;

    // sorting
    vector<int> v1 = {4,2,5,3,5,8,3};
    sort(v1.begin(), v1.end());
    REP(i, 0, v1.size()) cout << v1[i] << " ";
    cout << endl;

    sort(v1.rbegin(), v1.rend()); // reverse sorting
    REP(i, 0, v1.size()) cout << v1[i] << " ";
    cout << endl;

    int arr[] = {4,2,5,3,5,8,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    REP(i, 0, n) cout << arr[i] << " ";
    cout << endl;

    string s = "monkey";
    cout << s << endl;
    sort(s.begin(), s.end());
    cout << s << endl;
    
    // strings, sets, maps
    string s1 = "hello";
    string s2 = s1 + s1; // "hellohello"
    s2[5] = 'v';         // "hellovello"
    s2 = s1.substr(3,2); // "ll"

    set<int> my_set;
    my_set = {1,1,3,4};
    my_set.insert(5);   // add item to set
    my_set.erase(1);    // remove item from set
    my_set.count(3);    // check if item in set
    cout << "Set: ";
    for (auto x : my_set) cout << x << " ";
    cout << endl;

    map<string, int> my_map;
    my_map["monkey"] = 3;
    int a1 = my_map["donkey"];   // 0, default value

    // iteration through set/map
    for (auto x : my_set) {
        // cout << x << endl;
    }
    for (auto it = my_set.begin(); it != my_set.end(); it++) {
        // cout << *it << endl;
    }

    // bitset - array whose values are 1 or 0
    bitset<10> my_bitset;
    bitset<10> alt_bitset(string("0010011010"));
    my_bitset[1] = 1;
    my_bitset[3] = 1;
    my_bitset[4] = 0; 

    // stacks, queues, deques, priority queues
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(3);
    dq.pop_back();
    dq.pop_front();

    stack<int> stk;
    stk.push(1);
    stk.top();
    stk.pop();

    queue<int> q;
    q.push(1);
    q.front();
    q.pop();

    priority_queue<int> pq;
    pq.push(1);
    pq.top();
    pq.pop();


}