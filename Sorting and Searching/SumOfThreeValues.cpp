#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef long long ll;
using namespace std;
using namespace __gnu_pbds;

int main(){
    ll n, x; cin >> n >> x;
    vector<pair<ll, ll>> values(n);
    for (ll i = 0; i < n; i++){
        cin >> values[i].first;
        values[i].second = i + 1;
    }
    sort(values.begin(), values.end());
    if (n < 3){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    if (n == 3){
        if ((values[0].first + values[1].first + values[2].first) == x){
            cout << values[0].second << " " << values[1].second << " " << values[2].second << endl;
            return 0;
        }
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for(ll i = 0; i < n - 2; i++){
        for (ll j = i + 1; j < n - 1; j++){
            ll target = x - values[i].first - values[j].first;
            ll left = j + 1, right = n - 1;
            while (left <= right){
                ll mid = (left + right) / 2;
                if (values[mid].first == target){
                    cout << values[i].second << " " << values[j].second << " " << values[mid].second << endl;
                    return 0;
                }
                else if (values[mid].first < target) left = mid + 1;
                else right = mid - 1;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}