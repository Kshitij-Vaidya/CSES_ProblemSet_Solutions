#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n+1); // Increase the size of vector b by 1
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        b[a[i]] = i;
    }
    ll ans = 1; 
    for(ll i = 1; i < n; i++){
        if(b[i] > b[i+1]) ans++;
    }
    cout << ans << '\n';
    return 0;
}