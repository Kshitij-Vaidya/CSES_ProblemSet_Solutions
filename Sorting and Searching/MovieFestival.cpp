#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

bool cmp(pll a, pll b){
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    ll n; cin >> n;
    vector<pll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp); // Sort the movies based on their end time
    // We can always choose the movie that ends first (Greedy approach)
    ll ans = 0; ll end = 0;
    for (ll i = 0; i < n; i++){
        if (v[i].first >= end){
            ans++;
            end = v[i].second;
        }
    }
    cout << ans << '\n';
    return 0;
}