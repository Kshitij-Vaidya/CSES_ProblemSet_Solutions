#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
# define MOD 1000000007
# define Loop(i, a, b) for (ll i = a; i < b; i++)
# define Loopr(i, a, b) for (ll i = a; i > b; i--)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x; cin >> n >> x;
    vector<ll> prices(n), pages(n);
    Loop(i, 0, n) cin >> prices[i];
    Loop(i, 0, n) cin >> pages[i];

    vector<ll> max_pages(x + 1, 0);
    Loop(i, 0, n){
        for(ll j = x; j >= prices[i]; j--){
            max_pages[j] = max(max_pages[j], pages[i] + max_pages[j - prices[i]]);
        }
    }
    cout << max_pages[x] << endl;
    return 0;
}