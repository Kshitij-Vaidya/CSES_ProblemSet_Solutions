#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
# define Loop(i, a, b) for(int i = a; i < b; i++)
# define pb push_back


bool cycleSearch(vector<vector<ll>> &roads, vector<ll> &parent, vector<pair<bool, ll>> &visited, ll node, ll prev) {
    visited[node] = {true, 1};
    parent[node] = prev;

    for (auto curr : roads[node]) {
        if (!visited[curr].first) {
            if (cycleSearch(roads, parent, visited, curr, node)) return true;
        }
        else if (curr != prev && visited[curr].second == 1) {
            vector<ll> path;
            ll x = node;
            while (x != curr) {
                path.pb(x);
                x = parent[x];
            }
            path.pb(curr);
            path.pb(path[0]);
            cout << path.size() << '\n';
            for (auto i : path) {
                cout << i + 1 << " ";
            }
            cout << '\n';
            return true;
        }
        else if (curr != prev && visited[curr].second == 0) {
            if (cycleSearch(roads, parent, visited, curr, node)) {
                vector<ll> path;
                ll x = parent[curr];
                while (parent[x] != curr) {
                    path.pb(x);
                    x = parent[x];
                }
                cout << path.size() << '\n';
                for (auto i : path) {
                    cout << i + 1 << " ";
                }
                return true;
            }
        }
    }
    visited[node].second = 2;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<vector<ll>> roads(n);
    vector<ll> parent(n, -1);
    vector<pair<bool, ll>> visited(n, {false, 0});
    Loop(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        roads[a].pb(b);
        roads[b].pb(a);
    }

    Loop(i, 0, n) {
        if (visited[i].first) continue;
        if (cycleSearch(roads, parent, visited, i, -1)) return 0;
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}