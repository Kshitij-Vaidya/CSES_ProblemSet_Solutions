#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<pair<ll, ll>> tasks(n);
    // First : Duration, Second : Deadline
    for (ll i = 0; i < n; i++) cin >> tasks[i].first >> tasks[i].second;

    // From the start take the task with the smallest deadline
    // Sorting the tasks in ascending order of duration
    sort(tasks.begin(), tasks.end(), [](pair<ll, ll> a, pair<ll, ll> b){
        return a.first < b.first;
    });
    ll currTime = 0, reward = 0;
    for (ll i = 0; i < n; i++){
        currTime += tasks[i].first;
        reward += (tasks[i].second - currTime);
    }
    cout << reward << endl;
}