class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n), depth(n, 0);
        vector<int> parent(n, -1), rootMask(n, 0);
        int timer = 0;

        // Iterative DFS: avoids stack overflow on a chain-shaped tree.
        stack<tuple<int, int, bool>> st;
        st.push({0, -1, false});

        while (!st.empty()) {
            auto [u, p, exit] = st.top();
            st.pop();

            if (exit) {
                tout[u] = timer - 1;
                continue;
            }

            parent[u] = p;
            tin[u] = timer;
            timer++;

            rootMask[u] = (p == -1 ? 0 : rootMask[p])
                        ^ (1 << (s[u] - 'a'));

            st.push({u, p, true});

            for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];
                if (v == p) continue;

                depth[v] = depth[u] + 1;
                st.push({v, u, false});
            }
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, -1));

        for (int u = 0; u < n; u++)
            up[0][u] = parent[u];

        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++) {
                int p = up[j - 1][u];
                if (p != -1)
                    up[j][u] = up[j - 1][p];
            }
        }

        auto lca = [&](int u, int v) -> int {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j))
                    u = up[j][u];
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return parent[u];
        };

        // Fenwick Tree: range XOR update, point XOR query.
        vector<int> bit(n + 1, 0);

        auto add = [&](int idx, int val) {
            for (idx++; idx <= n; idx += idx & -idx)
                bit[idx] ^= val;
        };

        auto rangeXor = [&](int l, int r, int val) {
            add(l, val);
            if (r + 1 < n)
                add(r + 1, val);
        };

        auto pointQuery = [&](int idx) {
            int result = 0;
            for (idx++; idx > 0; idx -= idx & -idx)
                result ^= bit[idx];
            return result;
        };

        vector<bool> answer;

        for (const string &q : queries) {
            string type;
            int u, v;
            char c;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;

                int oldBit = 1 << (s[u] - 'a');
                int newBit = 1 << (c - 'a');

                int change = oldBit ^ newBit;

                // Only descendants of u have their root-prefix
                // masks changed.
                rangeXor(tin[u], tout[u], change);

                s[u] = c;
            } else {
                ss >> v;

                int common = lca(u, v);

                int maskU = rootMask[u] ^ pointQuery(tin[u]);
                int maskV = rootMask[v] ^ pointQuery(tin[v]);

                int mask = maskU ^ maskV
                         ^ (1 << (s[common] - 'a'));

                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};