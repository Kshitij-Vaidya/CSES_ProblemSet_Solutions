#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

typedef long long ll;   

int main(){
    ll n; cin >> n;
    vector<ll> songs(n);

    ll ans = 0; ll curr = 0;
    for (ll i = 0; i < n; i++){
        cin >> songs[i];
    }
    set<ll> s;
    for (ll i = 0; i < n; i++){
        // Two pointer approach to ensure that the current song is not present in the sequence
        while (s.find(songs[i]) != s.end()){
            s.erase(songs[curr]);
            curr++;
        }
        s.insert(songs[i]);
        ans = max(ans, i - curr + 1);
    }
    cout << ans << '\n';
}