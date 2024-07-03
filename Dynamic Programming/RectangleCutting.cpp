#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
# define Loop(i, a, b) for (ll i = a; i < b; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;
    vector<vector<ll>> cuts(a + 1, vector<ll>(b + 1, 1e9));
    Loop(i, 0, a + 1){
        Loop(j, 0, b + 1){
            if (i == j) cuts[i][j] = 0;
            else{
                Loop(k, 1, i) cuts[i][j] = min(cuts[i][j], cuts[k][j] + cuts[i - k][j] + 1);
                Loop(k, 1, j) cuts[i][j] = min(cuts[i][j], cuts[i][k] + cuts[i][j - k] + 1);
            }
        }
    }
    cout << cuts[a][b] << endl;
    return 0;
}