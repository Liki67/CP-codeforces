#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// The problem explicitly requires modulo 998244353.
const int MOD = 998244353;

int n, m;
vector<long long> a;
// Adjacency list storing pairs of {value of neighbor, neighbor index}
vector<vector<pair<long long, int>>> adj;
// Memoization: memo[u][prev_val] stores the count of paths continuing from u
// given the previous node had value prev_val.
vector<map<long long, int>> memo;

// Recursive function with memoization
// Returns the number of valid paths starting with the sequence (..., prev_val, a[u], ...)
// The count includes the path ending at 'u' itself.
int solve(int u, long long prev_val) {
    // Check if state is already computed
    if (memo[u].count(prev_val)) {
        return memo[u][prev_val];
    }

    long long current_val = a[u];
    long long next_target = prev_val + current_val;
    
    // Initialize count = 1 to account for the valid path ending at current node 'u'
    int count = 1; 

    // Find all neighbors v such that a[v] == next_target
    // Since adj[u] is sorted by value, we can use binary search
    auto it_start = lower_bound(adj[u].begin(), adj[u].end(), make_pair(next_target, -1));
    auto it_end = lower_bound(adj[u].begin(), adj[u].end(), make_pair(next_target + 1, -1));

    for (auto it = it_start; it != it_end; ++it) {
        int v = it->second;
        // Recursive step: sum up valid continuations
        count = (count + solve(v, current_val)) % MOD;
    }

    return memo[u][prev_val] = count;
}

void solve_test_case() {
    cin >> n >> m;
    
    // Reset data structures
    a.assign(n + 1, 0);
    adj.assign(n + 1, vector<pair<long long, int>>());
    memo.assign(n + 1, map<long long, int>());

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // Store neighbor with its value for easy sorting/searching
        adj[u].push_back({a[v], v});
    }

    // Sort adjacency lists by node value to enable binary search
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    long long total_paths = 0;

    // Iterate over all edges (u, v) as the "first two nodes" of a path
    for (int u = 1; u <= n; ++u) {
        for (auto& edge : adj[u]) {
            int v = edge.second;
            // The edge u->v forms the sequence [a[u], a[v]].
            // We call solve to count all paths that start with this prefix.
            total_paths = (total_paths + solve(v, a[u])) % MOD;
        }
    }

    cout << total_paths << endl;
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve_test_case();
    }
    return 0;
}