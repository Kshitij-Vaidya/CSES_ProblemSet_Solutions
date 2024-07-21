#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
# define Loop(i, a, b) for(int i = a; i < b; i++)
# define pb push_back


bool depthFirstSearch(vector<vector<ll>> &connections, vector<pair<bool, ll>> &teams, ll node, ll colour) {
    teams[node] = {true, colour};

    for (auto &curr : connections[node]) {
        if (teams[curr].second == 0) {
            if (!depthFirstSearch(connections, teams, curr, 3 - colour)) return false;
        } else if (teams[curr].second == colour) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<vector<ll>> connections(n);
    vector<pair<bool, ll>> teams(n, {false, 0});
    
    Loop(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        connections[a].pb(b);
        connections[b].pb(a);
    }

    bool answer = true;
    Loop(i, 0, n) {
        if (teams[i].first) continue;
        if (!depthFirstSearch(connections, teams, i, 1)) {
            answer = false;
            break;
        }
    }
    
    if (!answer) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        Loop(i, 0, n) {
            cout << teams[i].second << " ";
        }
        cout << '\n';
    }
}