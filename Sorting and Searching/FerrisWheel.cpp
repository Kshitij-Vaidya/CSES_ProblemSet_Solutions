#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
    ll n, x;
    cin >> n >> x;

    ll weights[n];
    // Input the weights of the n children
    for (ll i = 0; i < n; i++){
        cin >> weights[i];
    }
    sort(weights, weights+n);

    // Hold a pointer at the beginning and the end of the sorted array of weights
    ll l = 0; ll h = n - 1;
    int ans = 0; // No of gondolas required

    while(h >= l){
        if((weights[l] + weights[h]) <= x){
            ans++;
            l++;
            h--;
        }
        else{
            ans++;
            h--;
        }
    }
    cout << ans << endl;
}