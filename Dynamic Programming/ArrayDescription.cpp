#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
# define MOD 1000000007
# define Loop(i, a, b) for (ll i = a; i < b; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<ll> values(n);
    Loop(i, 0, n) cin >> values[i];
    vector<vector<ll>> ways(n, vector<ll>(m + 2, 0LL));
    // ways[i][j] gives the number of arrays such that arr[i] = j
    Loop(i, 0, n){
        if (i == 0){
            if (values[i] == 0) Loop(j, 1, m + 1) ways[0][j] = 1;
            else ways[0][values[0]] = 1;
        }
        else{
            if (values[i] == 0)
                Loop(j, 1, m + 1) ways[i][j] = (ways[i - 1][j] + ways[i - 1][j - 1] + ways[i - 1][j + 1]) % MOD;
            else ways[i][values[i]] = (ways[i - 1][values[i]] + ways[i - 1][values[i] - 1] + ways[i - 1][values[i] + 1]) % MOD;
            
        }
    }
    ll total = 0;
    Loop(i, 1, m + 1) total = (total + ways[n - 1][i]) % MOD;
    cout << total << endl;
    return 0;
}