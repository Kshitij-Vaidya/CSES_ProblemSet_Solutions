#include<iostream>
#include<map>

using namespace std;
typedef long long ll;

int main(){
    ll n, x;
    cin >> n >> x;

    map<ll, ll> index;
    bool found = false;
    for (ll i = 0; i < n; i++){
        ll num; cin >> num;
        if (index.find(x - num) != index.end()){
            cout << index[x - num] + 1 << ' ' << i + 1 << '\n';
            found = true;
            return 0;
        }
        index[num] = i;
    }
    if (!found) cout << "IMPOSSIBLE" << '\n';
    return 0;
}