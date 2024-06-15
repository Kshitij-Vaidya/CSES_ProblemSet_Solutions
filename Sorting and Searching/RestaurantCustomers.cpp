#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<ll> arr(n), dep(n);

    for (ll i = 0; i < n; i++){
        cin >> arr[i] >> dep[i];
    }
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    ll i = 0, j = 0, ans = 0, curr = 0;
    ll max = 0;
    while (i < n && j < n){
        // Arrival is before the departure
        if (arr[i] < dep[j]){
            curr++;
            i++;
            if (curr > max) max = curr;
        }
        else{
            curr--;
            j++;
        }
    }
    cout << max << '\n';
    return 0;
}