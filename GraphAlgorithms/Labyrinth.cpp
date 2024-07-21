#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
# define Loop(i, a, b) for (ll i = a; i < b; i++)


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<string> grid(n);
    Loop(i, 0, n) cin >> grid[i];

    pair<ll, ll> start, end;
    Loop(i, 0, n) {
        Loop(j, 0, m) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false)); // Keeps track of the visited nodes
    vector<vector<pair<ll, ll>>> parent(n, vector<pair<ll, ll>>(m, {-1, -1})); // Keeps track of the parent of each node
    queue<pair<ll, ll>> q; // Queue for BFS
    visited[start.first][start.second] = true;
    q.push(start);

    while(!q.empty()) {
        pair<ll, ll> curr = q.front(); q.pop();
        ll x = curr.first, y = curr.second;

        if (x - 1 >= 0 && grid[x - 1][y] != '#' && !visited[x - 1][y]) {
            q.push({x - 1, y});
            visited[x - 1][y] = true;
            parent[x - 1][y] = {x, y};
        }
        if (x + 1 < n && grid[x + 1][y] != '#' && !visited[x + 1][y]) {
            q.push({x + 1, y});
            visited[x + 1][y] = true;
            parent[x + 1][y] = {x, y};
        }
        if (y - 1 >= 0 && grid[x][y - 1] != '#' && !visited[x][y - 1]) {
            q.push({x, y - 1});
            visited[x][y - 1] = true;
            parent[x][y - 1] = {x, y};
        }
        if (y + 1 < m && grid[x][y + 1] != '#' && !visited[x][y + 1]) {
            q.push({x, y + 1});
            visited[x][y + 1] = true;
            parent[x][y + 1] = {x, y};
        }
    }

    if (!visited[end.first][end.second]) {
        cout << "NO\n";
        return 0;
    }
    vector<pair<ll, ll>> path;
    pair<ll, ll> curr = end;
    while (curr != start) {
        path.push_back(curr);
        curr = {parent[curr.first][curr.second]};
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    cout << "YES\n";
    cout << path.size() - 1 << '\n';

    Loop(i, 0, path.size() - 1) {
        if (path[i + 1].first == path[i].first + 1) cout << 'D';
        else if (path[i + 1].first == path[i].first - 1) cout << 'U';
        else if (path[i + 1].second == path[i].second + 1) cout << 'R';
        else if (path[i + 1].second == path[i].second - 1) cout << 'L';
    }
    cout << '\n';
    return 0;
}