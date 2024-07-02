#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<pair <pair<ll, ll>, ll>> v(n);
    // Read in the values
    for(ll i = 0; i < n; i++){
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(), v.end());  // Sort the values by start time
    vector<ll> rooms(n, -1); 
    ll room = 1;
    // Converting the priority queue to a min heap (It is a max heap by default)
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (ll i = 0; i < n; i++){
        if (pq.size() == 0){
            rooms[v[i].second] = room++;
            pq.push({v[i].first.second, room - 1}); // Add the exit time of the current room and the room assigned to the priority queue
        }
        // Else we allot the room to the room with the earliest exit time
        else{
            pair<ll, ll> p = pq.top();
            if (p.first < v[i].first.first){
                pq.pop();
                pq.push({v[i].first.second, p.second});
                rooms[v[i].second] = p.second;
            }
            else{
                rooms[v[i].second] = room++;
                pq.push({v[i].first.second, room - 1});
            }
        }   
    }
    cout << room - 1 << endl; // Total number of rooms needed 
    for (ll i = 0; i < n; i++){
        cout << rooms[i] << " ";
    }
    return 0;
}