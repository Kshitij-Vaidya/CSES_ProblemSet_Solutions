#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
# define Loop(i, a, b) for (ll i = a; i < b; i++)
# define LoopAuto(i, a) for (auto i : a)
# define pb push_back

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<vector<ll>> roads(n); // Considering the graph as an adjacency list
    Loop(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        roads[a].pb(b);
        roads[b].pb(a);
    }

    // Using a BFS to traverse the graph
    vector<bool> visited(n, false);
    vector<ll> pathHead;
    queue<ll> q;
    Loop(i, 0, n) {
        if (visited[i]) continue;
        pathHead.pb(i);
        q.push(i);
        visited[i] = true;

        while (!q.empty()) {
            ll curr = q.front(); q.pop();
            LoopAuto(node, roads[curr]) {
                if (visited[node]) continue;
                visited[node] = true;
                q.push(node);
            }
        }
    }
    cout << pathHead.size() - 1 << '\n';
    Loop(i, 0, pathHead.size() - 1) cout << pathHead[i] + 1 << " " << pathHead[i + 1] + 1 << '\n';
    return 0;
}