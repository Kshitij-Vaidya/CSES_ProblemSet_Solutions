#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
# define Loop(i, a, b) for (ll i = a; i < b; i++)
# define MAX 1e9

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> weights(n);
    Loop(i, 0, n) cin >> weights[i];
    vector<pair<ll, ll>> dp(1 << n); // {rides, weight}
    dp[0] = {1, 0};
    Loop(i, 1, 1 << n){
        dp[i] = {21, 0};
        Loop(j, 0, n){
            if (1 & (i >> j)){
                auto prev = dp[i ^ (1 << j)];
                if (prev.second + weights[j] <= x) {
                    prev.second += weights[j];
                }
                else{
                    prev.first++;
                    prev.second = weights[j];
                }
                dp[i] = min(dp[i], prev);
            }
        }
    }
    cout << dp[(1 << n) - 1].first << endl;
    return 0;
}