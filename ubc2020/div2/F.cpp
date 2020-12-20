#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void read_array(vector<string> & v, int n) {
    string num;
    while (n--) {
        cin >> num;
        v.push_back(num);
    }
}

bool DFS(unordered_map<string, unordered_set<string>>& graph, vector<string>& path, vector<string>& ans, unordered_set<string>& visited, string src, string dest) {
    if (src == dest) {
        ans = path;
        return true;
    }

    if (visited.count(src)) return false;
    visited.insert(src); 

    for (string nbor : graph[src]) {
        path.push_back(nbor);
        int found = DFS(graph, path, ans, visited, nbor, dest);
        path.pop_back();
        if (found) return true;
    }

    return false;
}

string solve(vector<vector<string>>& pieces, int N) {
    unordered_map<string, unordered_set<string>> adjList;

    for (int i = 0; i < N; i++) {
        auto& piece = pieces[i];
        string src = piece[0];
        for (int i = 1; i < piece.size(); i++) {
            adjList[src].insert(piece[i]);
            adjList[piece[i]].insert(src);
        }
    }

    string src = pieces[N][0];
    string dest = pieces[N][1];
    
    vector<string> path;
    vector<string> ans;
    unordered_set<string> visited;

    int found = DFS(adjList, path, ans, visited, src, dest);
    if (!found) return "no route found";
    
    string res = src;

    for (string& s : ans) {
        res += " " + s;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string entry;
    getline(cin, entry);
    int N = stoi(entry);

    vector<vector<string>> pieces;
    for (int i = 0; i <= N; i++) {
        getline(cin, entry);

        stringstream ss(entry);

        vector<string> piece;
        string s;

        while (ss >> s) {
            piece.push_back(s);
        }

        pieces.push_back(piece);
    }

    // cout << pieces.size() << endl;

    // for (auto& piece : pieces) {
    //     for (auto& s : piece) {
    //         cout << s << " ";
    //     }
    //     cout << "\n";
    // }


    cout << solve(pieces, N) << "\n";

    
    cout.flush();
    return 0;
}