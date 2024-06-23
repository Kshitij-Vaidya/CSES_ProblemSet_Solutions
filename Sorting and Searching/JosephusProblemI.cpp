#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    queue<ll> q;
    // Add all the numbers to the queue
    for (ll i = 1; i <= n; i++){
        q.push(i);
    }
    bool check = false;
    while(!q.empty()){
        ll x = q.front();
        q.pop();

        if (check) cout << x << " ";
        else q.push(x);
    
        check = !check;
    }
    return 0;
}