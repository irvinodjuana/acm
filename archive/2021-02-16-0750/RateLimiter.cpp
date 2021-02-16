#include <bits/stdc++.h>
using namespace std;

// shortened type names
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;

// common utils

vector<vector<char>> read_matrix(int n, int m) {vector<vector<char>> grid(n, vector<char>(m));for (int i = 0; i < n; i++) {string s;cin >> s;for (int j = 0; j < m; j++) {grid[i][j] = s[j];}}return grid;}
bool inBounds(int i, int j, int n, int m) {return i >= 0 && i < n && j >= 0 && j < m;}
void print_vector(vector<int> v) {for (int i = 0; i < v.size(); i++) {cout << v[i] << " ";}cout << "\n";}
vector<int> read_vector(int n) {vector<int> v;int num;while (n--) {cin >> num;v.push_back(num);}return v;}

/**
 * SIG February Coding Challenge on CodeSignal
 * Rate Limiter problem
 * 
 */

vector<int> rateLimitPerIp(vector<long long> timestamps, int limit, int window) {
    int n = timestamps.size();
    vector<int> accepted(n, 0);

    int left = 0;
    int numRequestsInWindow = 0;

    // window = [left, right]
    for (int right = 0; right < n; right++) {
        while (timestamps[left] < timestamps[right] - window) {
            numRequestsInWindow -= accepted[left];
            left++;
        }

        if (numRequestsInWindow < limit) {
            numRequestsInWindow++;
            accepted[right] = 1;
        }
    }

    return accepted;
}


vector<int> rateLimiter2(vector<long long> timestamps, vector<string> ipAddresses, int limit, int window) {
    unordered_map<string, vector<long long>> ip_timestamps;
    unordered_map<string, vector<int>> ip_indexes;

    int n = timestamps.size();

    for (int i = 0; i < n; i++) {
        string ip = ipAddresses[i];
        ip_timestamps[ip].push_back(timestamps[i]);
        ip_indexes[ip].push_back(i);
    }

    vector<int> accepted(n, 0);

    for (auto p : ip_timestamps) {
        string ip = p.first;
        auto& times = p.second;
        auto& idxs = ip_indexes[ip];
        auto& rates = rateLimitPerIp(times, limit, window);

        for (int i = 0; i < rates.size(); i++) {
            accepted[idxs[i]] = rates[i];
        }
    }

    return accepted;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // code
    
    cout.flush();
    return 0;
}