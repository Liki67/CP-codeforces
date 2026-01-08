#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Global/Helper data structures
vector<vector<int>> adj;
vector<vector<int>> parents_at_depth;

// Standard DFS to record the parent of each node at every depth
void find_depths(int u, int p, int d) {
    if (d >= parents_at_depth.size()) {
        parents_at_depth.push_back({});
    }
    
    // Store the parent of the current node at this depth level
    parents_at_depth[d].push_back(p);

    for (int v : adj[u]) {
        if (v != p) {
            find_depths(v, u, d + 1);
        }
    }
}

void solve() {
    int N;
    if (!(cin >> N)) return;

    // Reset data for each test case
    adj.assign(N, vector<int>());
    parents_at_depth.clear();

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // Convert to 0-indexed
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_depths(0, -1, 0);

    int max_ans = 0;
    for (int d = 0; d < parents_at_depth.size(); d++) {
        int count = parents_at_depth[d].size();
        
        // Logic: Check if all nodes at this depth share the exact same parent
        bool all_same_parent = true;
        int first_parent = parents_at_depth[d][0];
        
        for (int p : parents_at_depth[d]) {
            if (p != first_parent) {
                all_same_parent = false;
                break;
            }
        }

        // If d > 0 and they share a parent, add 1 (per your original logic)
        if (d > 0 && all_same_parent) {
            max_ans = max(max_ans, count + 1);
        } else {
            max_ans = max(max_ans, count);
        }
    }

    cout << max_ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}