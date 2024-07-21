#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
# define Loop(i, a, b) for (ll i = a; i < b; i++)
# define MAX 1e9

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<string> grid(n);
    Loop(i, 0, n) cin >> grid[i];
    vector<vector<ll>> visited(n, vector<ll>(m, 0)); // Keeps track of the visited nodes
    queue<pair<ll, ll>> q; // Queue for BFS
    ll count = 0;

    Loop(i, 0, n) {
        Loop(j, 0, m) {
            if (grid[i][j] == '#' || visited[i][j]) continue;
            q.push({i, j});
            visited[i][j] = 1;
            count++;
            while (!q.empty()) {
                // Processing the first node in the queue
                ll x = q.front().first, y = q.front().second;
                q.pop();

                if (x - 1 >= 0 && grid[x - 1][y] == '.' && !visited[x - 1][y]) {
                    q.push({x - 1, y});
                    visited[x - 1][y] = 1;
                }
                if (x + 1 < n && grid[x + 1][y] == '.' && !visited[x + 1][y]) {
                    q.push({x + 1, y});
                    visited[x + 1][y] = 1;
                }
                if (y - 1 >= 0 && grid[x][y - 1] == '.' && !visited[x][y - 1]) {
                    q.push({x, y - 1});
                    visited[x][y - 1] = 1;
                }
                if (y + 1 < m && grid[x][y + 1] == '.' && !visited[x][y + 1]) {
                    q.push({x, y + 1});
                    visited[x][y + 1] = 1;
                }
            }
        }
    }
    cout << count << '\n';
    return 0;
}