#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
# define MOD 1000000007
# define Loop(i, a, b) for (ll i = a; i < b; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    ll sum = (n * (n + 1)) / 2;

    if (sum % 2 != 0){
        cout << 0 << endl;
        return 0;
    }
    // We want to try to make the subset sum to be sum/2
    sum /= 2;
    // Let us assume that we have ways[i][j] = number of ways to make sum j using first i numbers
    // We also assume that n is always in the second subset (Prevents double counting)

    vector<vector<ll>> ways(n, vector<ll>(sum + 1, 0));
    ways[0][0] = 1;
    
    Loop(i, 1, n){
        Loop(j, 0, sum + 1){
            ways[i][j] = (ways[i - 1][j] + (j >= i ? ways[i - 1][j - i] : 0)) % MOD;
        }
    }
    cout << ways[n - 1][sum] << endl;
    return 0;
}