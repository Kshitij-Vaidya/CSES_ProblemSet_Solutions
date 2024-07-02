#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <set>

typedef long long ll;
using namespace std;
using namespace __gnu_pbds;


int main(){
    ll n; cin >> n;
    vector<pair<ll, ll>> values(n);
    for (ll i = 0; i < n; i++){
        cin >> values[i].first;
        values[i].second = i;
    }
    vector<ll> ans(n, 0);
    stack<ll> s;
    for (ll i = 0; i < n; i++){
        while (!s.empty() && values[s.top()].first >= values[i].first) s.pop();
        if (s.empty()) ans[i] = 0;
        else ans[i] = s.top() + 1;
        s.push(i);
    }
    for(auto x: ans) cout << x << " ";
    return 0;
}