#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
# define MOD 1000000007
# define MAX 1000001
# define Loop(i, a, b) for (ll i = a; i < b; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // We consider the intersections between the two towers 
    // There are 8 possible configurations for the intersections
    // The configurations at each intersection make a Finite State Machine
    vector<vector<ll>> ways(MAX, vector<ll>(8, 0LL));
    // We can start at any configuration
    Loop(i, 0, 8) ways[0][i] = 1;
    Loop(i, 1, MAX){
        Loop(j, 0, 8){
            if (j == 0 || j == 2 || j == 3 || j == 4 || j == 5)
                ways[i][j] = (ways[i - 1][0] + ways[i - 1][1] + ways[i - 1][3] + ways[i - 1][4] + ways[i - 1][5]) % MOD;
            else
                ways[i][j] = (ways[i - 1][2] + ways[i - 1][6] + ways[i - 1][7]) % MOD;
        }
    }

    ll t; cin >> t;
    while (t--){
        ll n; cin >> n;
        // The last configuration must always be one of the configurations that end with a 3 or a 7
        cout << (ways[n - 1][2] + ways[n - 1][6]) % MOD << endl;
    }
}