#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> trees, unordered_map<int,int> heights) {
    unordered_map<int,int> fromLeft;
    unordered_map<int,int> fromRight;
    unordered_set<int> positions;

    for (int i = 0; i < trees.size(); i++) {
        int tree = trees[i];
        int pos = tree + heights[tree];
        int curr = fromLeft[tree] + heights[tree];
        fromLeft[pos] = max(fromLeft[pos], curr);
        positions.insert(tree);
        positions.insert(pos);
    }

    for (int i = trees.size() - 1; i >= 0; i--) {
        int tree = trees[i];
        int pos = tree - heights[tree];
        int curr = fromRight[tree] + heights[tree];
        fromRight[pos] = max(fromRight[pos], curr);
        positions.insert(pos);
    }

    int best = 0;

    for (int pos : positions) {
        best = max(best, fromLeft[pos] + fromRight[pos]);
    }

    return best;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("input_timber.txt");
    ofstream fout("output_timber.txt");

    int tests;
    fin >> tests;

    for (int t = 0; t < tests; t++) {
        // code here
        int N;
        fin >> N;
        vector<int> trees;
        unordered_map<int,int> heights;
        int tree, height;

        for (int i = 0; i < N; i++) {
            fin >> tree >> height;
            trees.push_back(tree);
            heights[tree] = height;
        }

        sort(trees.begin(), trees.end());
        int soln = solution(trees, heights);

        fout << "Case #" << t+1 << ": " << soln << "\n";
    }

    fin.close();
    fout.close();
    
    cout.flush();
    return 0;
}