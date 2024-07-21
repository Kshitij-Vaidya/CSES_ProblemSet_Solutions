#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
# define Loop(i, a, b) for(int i = a; i < b; i++)
# define LoopAuto(i, a) for(auto i : a)
# define pb push_back
# define mp make_pair

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<vector<ll>> connections(n);
    Loop(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        connections[a].pb(b);
        connections[b].pb(a);
    }

    vector<ll> parent(n, -1);
    vector<bool> visited(n, false);
    queue<ll> q;
    q.push(0); // Start from node 1
    visited[0] = true;

    while (!q.empty()) {
        ll node = q.front(); q.pop();
        LoopAuto(i, connections[node]) {
            if (!visited[i]) {
                visited[i] = true;
                parent[i] = node;
                q.push(i);
            }
        }
    }
    if (!visited[n - 1]) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<ll> path;
        ll node = n - 1;
        while (node != -1) {
            path.pb(node);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        LoopAuto(i, path) {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}