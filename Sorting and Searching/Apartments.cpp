#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    // Define vectors a and b to store the apartment sizes and the desired sizes
    vector<ll> a(n), b(m);

    // Read apartment size
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    // Read desired size
    for(ll i = 0; i < m; i++){
        cin >> b[i];
    }

    // Sort the vectors
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Use a two-pointer approach to find the number of apartments that can be assigned
    ll i = 0, j = 0, ans = 0;
    while(i < n && j < m){
        if(abs(a[i] - b[j]) <= k){
            i++;
            j++;
            ans++;
        } else if (a[i] < b[j]){
            i++;
        } else{
            j++;
        }
    }
    cout << ans << endl;
}