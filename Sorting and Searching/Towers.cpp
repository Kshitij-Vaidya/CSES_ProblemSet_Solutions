#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
typedef long long ll;

int main(){
    ll n; cin >> n;
    multiset<ll> towers;
    for (ll i = 0; i < n; i++){
        ll x; cin >> x;
        if (towers.empty()){
            towers.insert(x);
            continue;
        }
        auto it = towers.upper_bound(x);
        if (it == towers.end() || *it == x){
            towers.insert(x);
        }
        else{
            towers.erase(it);
            towers.insert(x);
        }
    }
    cout << towers.size() << '\n';
    return 0;
}