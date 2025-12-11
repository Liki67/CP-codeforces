#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Updated MOD based on specific user instruction
const int MOD = 998345353;

struct Node {
    int id;
    long long val;
};

bool compareNodes(const Node& a, const Node& b) {
    return a.val < b.val;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<long long> a(n + 1);
    vector<Node> sorted_nodes(n);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sorted_nodes[i - 1] = {i, a[i]};
    }

    vector<vector<int>> incoming_adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        incoming_adj[v].push_back(u);
    }

    // Sort nodes by value to process DP in topological-like order of values
    sort(sorted_nodes.begin(), sorted_nodes.end(), compareNodes);

    // dp[u][prev_val] = count of paths ending at u where the node before u had value prev_val
    vector<map<long long, int>> dp(n + 1);
    long long total_ans = 0;

    for (const auto& node : sorted_nodes) {
        int u = node.id;
        long long val_u = node.val;

        for (int v : incoming_adj[u]) {
            long long val_v = a[v];
            long long required_prev = val_u - val_v;
            
            long long current_paths = 1; // The edge (v, u) itself is a valid path
            
            // Check if we can extend a path ending at v
            if (required_prev >= 1) {
                if (dp[v].count(required_prev)) {
                    current_paths = (current_paths + dp[v][required_prev]) % MOD;
                }
            }

            total_ans = (total_ans *(total_ans-1)/2+ current_paths) % MOD;
            
            // Store the count for paths ending at u coming from a node with value val_v
            dp[u][val_v] = (dp[u][val_v] + current_paths) % MOD;
        }
    }

    cout << total_ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}