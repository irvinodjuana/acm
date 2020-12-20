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

void read_array(vector<int> & v, int n) {
    int num;
    while (n--) {
        cin >> num;
        v.push_back(num);
    }
}

constexpr int LEFT = -1;
constexpr int RIGHT = -2;

class Node {
public:
    int x;
    int y;
    int r;
   unordered_set<Node*> neighbours;

    Node(int x_, int y_, int r_): x(x_), y(y_), r(r_) {}

    void addEdge(Node* nbor) {
        neighbours.insert(nbor);
    }
};

void addEdge(Node* a, Node* b) {
    a->neighbours.insert(b);
    b->neighbours.insert(a);
}

bool areNeighbours(Node* a, Node* b) {
    double x1 = a->x, x2 = b->x;
    double y1 = a->y, y2 = b->y;
    double r1 = a->r, r2 = b->r;

    double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    return dist < r1 + r2;
}

bool isPath(Node* left, Node* right) {
    unordered_set<Node*> visited;
    stack<Node*> stk;
    stk.push(left);

    while (!stk.empty()) {
        Node* node = stk.top();
        stk.pop();

        if (visited.count(node)) continue;
        if (node == right) return true;

        visited.insert(node);

        for (auto nbor : node->neighbours) {
            stk.push(nbor);
        }
    }

    return false;
}

int solve(vector<vector<int>>& sensors) {
    vector<Node*> nodes;
    Node* left = new Node(LEFT, LEFT, LEFT);
    Node* right = new Node(RIGHT, RIGHT, RIGHT);

    for (auto& sensor : sensors) {
        nodes.push_back(new Node(sensor[0], sensor[1], sensor[2]));
    }

    for (int i = 0; i < nodes.size(); i++) {
        Node* curr = nodes[i];
        if (curr->r > curr->x) addEdge(left, curr);
        if (curr->x + curr->r > 200) addEdge(right, curr);

        for (int j = 0; j < i; j++) {
            Node* prev = nodes[j];
            if (areNeighbours(prev, curr)) {
                addEdge(prev, curr);
            }
        }

        if (isPath(left, right)) return i;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vector<int>> sensors(N);

    for (int i = 0; i < N; i++) {
        read_array(sensors[i], 3);
    }

    cout << solve(sensors) << "\n";

    
    cout.flush();
    return 0;
}