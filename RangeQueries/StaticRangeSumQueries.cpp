#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
# define Loop(i, a, b) for (int i = a; i < b; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, q; cin >> n >> q;
    vector<ll> arr(n), prefixSum(n+1, 0);
    // Using a prefix sum array to hold the prefix sums as well
    Loop(i, 0, n) { 
        cin >> arr[i];
        prefixSum[i+1] = prefixSum[i] + arr[i];
    }

    // Handling q queries
    while (q--) {
        ll a, b; cin >> a >> b;
        cout << prefixSum[b] - prefixSum[a - 1] << '\n';
    }
    return 0;
}